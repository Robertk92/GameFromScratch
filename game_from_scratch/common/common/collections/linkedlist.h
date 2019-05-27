#ifndef __LIST_GUARD__
#define __LIST_GUARD__

#include <common/collections/collection.h>
#include <common/system/system.h>

template<class T> class COMMON LinkedList : public Collection<T> {
public:
	
	virtual ~LinkedList() {
		
	}

};

#endif