#ifndef __OBJECT_GUARD__
#define __OBJECT_GUARD__

#include <common/system/system.h>

class COMMON Object {
public:
	virtual ~Object() = 0;
};
Object::~Object() { } 

#endif //__OBJECT_GUARD__
