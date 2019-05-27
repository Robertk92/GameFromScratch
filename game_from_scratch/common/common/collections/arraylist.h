#ifndef __ARRAYLIST_GUARD__
#define __ARRAYLIST_GUARD__

#include <common/diagnostics/assertion.h>
#include <common/collections/collection.h>
#include <common/system/memory.h>
#include <common/system/system.h>

template<class T> class COMMON ArrayList : public Collection<T> {
public:
	ArrayList(size_t capacity = 0) {
		Setup(nullptr, 0, capacity);
	}

	ArrayList(T* items, size_t count) {
		Setup(items, count, count);
	}

	template<size_t N> ArrayList(T (&items)[N]) {
		Setup(items, N, N);
	}
	
	ArrayList(ArrayList<T>& collection, bool sameCapacity = false) {
		Setup(collection._head, collection._size, sameCapacity ? collection._capacity : collection._size);
	}

	ArrayList(const ArrayList<T>& copy) {
		Setup(copy._head, copy._size, copy._capacity);
	}

	virtual ~ArrayList() {
		free(_head);
	}

	const T* Begin() override {
		return _head;
	}

	const T* End() override {
		return _head + _size;
	}

	const T* Next() override {
		return ++_iterator;
	}

	inline size_t Size() { return _size; }
	inline size_t Capacity() { return _capacity; }
	inline T& operator[] (uint32_t index) { return _head[index]; }

	void Push(T item) {
		PushRange(&item, 1);
	}

	void PushRange(T* items, size_t count) {
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
		T* newPtr = nullptr;
		if (_capacity > 0) {
			ensure_intmul_no_overflow(_capacity, sizeof(T));
			T* copy = (T*)Memory::Malloc(_capacity * sizeof(T));
			memcpy(copy, _head, _size * sizeof(T));
			newPtr = copy;
		}
		free(_head);
		_head = newPtr;
	}

	void Clear(bool shrink = true) {
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
			PushRange(items, itemCount);
			if (capacity > itemCount) {
				SetCapacity(capacity);
			}
		}
		else {
			SetCapacity(capacity);
		}
	}

	T* _head;
	T* _iterator;
	size_t _size;
	size_t _capacity;
};

#endif // __ARRAYLIST_GUARD__
