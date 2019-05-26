#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include <common/system/object.h>
#include <common/diagnostics/assertion.h>
#include <common/system/memory.h>
#include <common/system/system.h>

#define foreach(iterator, collection) \
	auto iterator = collection.GetHead(); \
	for(size_t i = 0; i < collection.Size(); i++, iterator++) \

template<class T> class COMMON Collection : public Object {
public:
	Collection(size_t capacity = 0) {
		Setup(nullptr, 0, capacity);
	}

	Collection(T* items, size_t count) {
		Setup(items, count, count);
	}

	template<size_t N> Collection(T (&items)[N]) {
		Setup(items, N, N);
	}
	
	Collection(Collection<T>& collection, bool sameCapacity = false) {
		Setup(collection._head, collection._size, sameCapacity ? collection._capacity : collection._size);
	}

	Collection(const Collection<T>& copy) {
		Setup(copy._head, copy._size, copy._capacity);
	}

	virtual ~Collection() {
		delete[] _head;
	}

	inline T* GetHead() { return _head; }
	inline size_t Size() { return _size; }
	inline size_t Capacity() { return _capacity; }
	inline T& operator[] (int index) { return _head[index]; }

protected:
	void Push(T* items, size_t count) {
		if (_size >= _capacity) {
			SetCapacity(_capacity + count);
		}
		_size += count;
		for (size_t i = 0; i < count; i++) {
			_head[_size - count + i] = items[i];
		}
	}

	void Insert(T item, uint32_t index) {
		ensure(index >= 0 && index < _size);
		if (_size >= _capacity) {
			SetCapacity(_capacity + 1);
		}
		_size++;
		ensure_intmul_no_overflow((_size - index), sizeof(T));
		memmove(_head + index + 1, _head + index, (_size - index) * sizeof(T));
		_head[index] = item;
	}

	void RemoveAt(uint32_t index, bool shrink = false) {
		ensure(index >= 0 && index < _size);
		if (index != _size - 1) {	
			ensure_intmul_no_overflow((_size - index), sizeof(T));
			memmove(_head + index - 1, _head + index, (_size - index) * sizeof(T));
		}
		_size--;
		if (shrink) {
			SetCapacity(_size);
		}
	}

	void SetCapacity(size_t capacity) {
		ensure(capacity >= _size);
		if (_capacity == capacity) {
			return;
		}
		
		_capacity = capacity;
		if (_capacity > 0) {
			ensure_intmul_no_overflow(_capacity, sizeof(T));
			T* copy = (T*)Memory::Malloc(_capacity * sizeof(T));
			memcpy(copy, _head, _size * sizeof(T));
			delete[] _head;
			_head = copy;
		}
		else {
			_head = nullptr;
		}
	}

	void Clear(bool shrink = false) {
		delete[] _head;
		_size = 0;
		if (shrink) {
			SetCapacity(0);
		}
	}

private:
	void Setup(T* items, size_t itemCount, size_t capacity) {
		_size = 0;
		_head = nullptr;
		if (items != nullptr) {
			Push(items, itemCount);
			if (capacity > itemCount) {
				SetCapacity(capacity);
			}
		}
		else {
			SetCapacity(capacity);
		}
	}

	T* _head;
	size_t _capacity;
	size_t _size;
};

#endif
