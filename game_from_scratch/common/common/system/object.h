#ifndef __OBJECT_GUARD__
#define __OBJECT_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON Object {
	public:
		virtual ~Object() = 0;
	};
	Object::~Object() { }
}

#endif //__OBJECT_GUARD__
