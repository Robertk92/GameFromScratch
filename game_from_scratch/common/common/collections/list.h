#ifndef __LIST_GUARD__
#define __LIST_GUARD__

#include <common/collections/collection.h>
#include <common/system/system.h>

template<class T> class COMMON List : public Collection<T> {
public:
	List(size_t capacity = 0) : Collection<T>(capacity) { }
	List(T* items, size_t count) : Collection<T>(items, count) { }
	template<size_t N> List(T (&items)[N]) : Collection<T>(items) { }
	List(Collection<T>& collection) : Collection<T>(collection) { }
	List(const List<T>& copy) : Collection<T>(copy) { }

	void Push(T item) { Collection<T>::Push(item); }
	void Insert(T item, uint32_t index) { Collection<T>::Insert(item, index); }
	void RemoveAt(uint32_t index, bool shrink = false) { Collection<T>::RemoveAt(index, shrink); }
	void Remove(T item) { not_implemented(); }
	void Clear(bool shrink = false) { Collection<T>::Clear(shrink); }
	void SetCapacity(size_t capacity) { Collection<T>::SetCapacity(capacity); }

	virtual ~List() {
		
	}
};

#endif