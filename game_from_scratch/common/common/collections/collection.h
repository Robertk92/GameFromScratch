#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include <common/system/object.h>

#define foreach(item, collection) \
	for (auto item = collection.Begin(); item != collection.End(); item = collection.Next()) \

template<class T> class COMMON Collection : public Object {
public:
	virtual const T* Begin() = 0;
	virtual const T* End() = 0;
	virtual const T* Next() = 0;
};

#endif // __COLLECTION_GUARD__
