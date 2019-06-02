#ifndef __DELEGATE_GUARD__
#define __DELEGATE_GUARD__
#include <common/system/system.h>
#include <common/collections/arraylist.h>

namespace Common {
	template<class TMember, class... TArgs> struct COMMON DelegateBinding {
		TMember* _member;
		void(TMember::*_funcPtr)(TArgs...);
	};

	template<class TMember, class... TArgs> class COMMON MemberDelegate {
	public:
		MemberDelegate() { }
		void bind(TMember* member, void(TMember::*funcPtr)(TArgs...)) {
			DelegateBinding<TMember, TArgs...> binding = DelegateBinding<TMember, TArgs...>();
			binding._member = member;
			binding._funcPtr = funcPtr;
			_bindings.push(binding);
		}

		void invoke(TArgs... args) {
			for (Size i = 0; i < _bindings.size(); i++) {
				ensure(_bindings[i]._member != nullptr && "Member object of function pointer was deleted");
				(_bindings[i]._member->*_bindings[i]._funcPtr)(args...);
			}
		}

	private:
		ArrayList<DelegateBinding<TMember, TArgs...>> _bindings;
	};
}
#endif//__DELEGATE_GUARD__
