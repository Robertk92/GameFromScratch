#ifndef __DELEGATE_GUARD__
#define __DELEGATE_GUARD__
#include <common/system/system.h>
#include <common/collections/arraylist.h>

namespace Common {
	class COMMON Delegate {
	public:
		virtual ~Delegate() = 0;
	};

	template<class TMember, class... TArgs> class COMMON MemberDelegate : public Delegate {
	private:
		struct COMMON Binding {
			TMember* _member;
			void(TMember::*_funcPtr)(TArgs...);
		};
	public:
		MemberDelegate() { }
		virtual ~MemberDelegate() { }

		void bind(TMember* member, void(TMember::*funcPtr)(TArgs...)) {
			Binding binding = Binding();
			binding._member = member;
			binding._funcPtr = funcPtr;
			_bindings.push(binding);
		}

		void unbind(TMember* member, void(TMember::*funcPtr)(TArgs...)) {
			int idx = -1;
			for (Size i = 0; i < _bindings.size(); ++i) {
				if (_bindings[i]._member == member && _bindings[i]._funcPtr == funcPtr) {
					idx = static_cast<int>(i);
					break;
				}
			}
			if (idx > -1) {
				_bindings.remove_at(idx);
			}
		}

		void invoke(TArgs... args) {
			for (Size i = 0; i < _bindings.size(); i++) {
				ensure(_bindings[i]._member != nullptr && "Member object of function pointer was deleted");
				(_bindings[i]._member->*_bindings[i]._funcPtr)(args...);
			}
		}

	private:
		ArrayList<Binding> _bindings;
	};

	template<class... TArgs> class COMMON GlobalDelegate : public Delegate {
	private:
		struct COMMON Binding {
			void(*_funcPtr)(TArgs...);
		};
	public:
		GlobalDelegate() { }
		virtual ~GlobalDelegate() { }

		void bind(void(*funcPtr)(TArgs...)) {
			Binding binding = Binding();
			binding._funcPtr = funcPtr;
			_bindings.push(binding);
		}

		void invoke(TArgs... args) {
			for (Size i = 0; i < _bindings.size(); i++) {
				(*_bindings[i]._funcPtr)(args...);
			}
		}

	private:
		ArrayList<Binding> _bindings;
	};
}
#endif//__DELEGATE_GUARD__
