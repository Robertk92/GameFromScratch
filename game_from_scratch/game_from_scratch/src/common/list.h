#ifndef __LIST_GUARD__
#define __LIST_GUARD__

#include "collection.h"

template<class T> class List : public Collection<T> {
public:
	List(int capacity = 0) : Collection<T>(capacity) {

	}

	void Push(T item) { Collection<T>::Push(item); }
	void Insert(T item, int index) { Collection<T>::Insert(item, index); }
	void RemoveAt(int index, bool shrink = false) { Collection<T>::RemoveAt(index, shrink); }
	void Clear(bool shrink = false) { Collection<T>::Clear(shrink); }
	void SetCapacity(int capacity) { Collection<T>::SetCapacity(capacity); }

	virtual ~List() {

	}
};

#endif