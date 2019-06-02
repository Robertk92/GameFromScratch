#ifndef __DELEGATE_GUARD__
#define __DELEGATE_GUARD__
#include <common/system/system.h>
#include <common/collections/arraylist.h>

namespace Common {
	template<class TMember> struct COMMON DelegateBinding {
		TMember* _member;
		void(TMember::*_funcPtr)();
	};

	template<class TMember> class COMMON MemberDelegate {
	public:
		MemberDelegate() { }
		void bind(TMember* member, void(TMember::*funcPtr)()) {
			DelegateBinding<TMember> binding = DelegateBinding<TMember>();
			binding._member = member;
			binding._funcPtr = funcPtr;
			_bindings.push(binding);
		}

		void invoke() {
			for (Size i = 0; i < _bindings.size(); i++) {
				ensure(_bindings[i]._member != nullptr && "Member object of function pointer was deleted");
				(_bindings[i]._member->*_bindings[i]._funcPtr)();
			}
		}

	private:
		ArrayList<DelegateBinding<TMember>> _bindings;
	};
}
#endif//__DELEGATE_GUARD__
