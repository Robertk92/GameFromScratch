#ifndef __ARRAYLIST_GUARD__
#define __ARRAYLIST_GUARD__

#include <common/diagnostics/assertion.h>
#include <common/collections/collection.h>
#include <common/system/memory.h>
#include <common/system/system.h>

template<class T> class COMMON ArrayList : public Collection<T> {
	using BaseIter = Collection<T>::Iterator;

public:
	class COMMON ReverseIterator : public BaseIter {
	public:
		ReverseIterator(const T* head, const T* tail) : BaseIter(head, tail) {
			BaseIter::_current = head;
			_beginReached = false;
		}

		const T* next() override {
			ENSURE(!_beginReached && "Attempting to iterate backwards past the beginning of the collection");
			if (BaseIter::_current - 1 == BaseIter::_head) {
				_beginReached = true;
			}
			return --BaseIter::_current;
		}

		inline void operator--() {
			next();
		}

		inline void operator-=(int decrement) {
			for (size_t i = 0; i < decrement; i++) {
				next();
			}
		}

		inline ReverseIterator& operator--(int decrement) {
			for (size_t i = 0; i < decrement; i++) {
				next();
			}
			return *this;
		}

		inline ReverseIterator operator-(int decrement) {
			return ReverseIterator(BaseIter::_head - decrement, BaseIter::_tail);
		}

		inline ReverseIterator operator+(int increment) {
			return ReverseIterator(BaseIter::_head + increment, BaseIter::_tail);
		}

	private:
		bool _beginReached;
	};

	class COMMON Iterator : public BaseIter {
	public:
		Iterator(const T* head, const T* tail) : BaseIter(head, tail) {
			BaseIter::_current = head;
			_endReached = false;
		}

		const T* next() override {
			ENSURE(!_endReached && "Attempting to iterate past the end of the collection");
			if (BaseIter::_current + 1 == BaseIter::_tail) {
				_endReached = true;
			}
			return ++BaseIter::_current;
		}

		inline Iterator operator-(int decrement) {
			return Iterator(BaseIter::_head - decrement, BaseIter::_tail);
		}

		inline Iterator operator+(int increment) {
			return Iterator(BaseIter::_head + increment, BaseIter::_tail);
		}

		inline void operator++() {
			next();
		}

		inline void operator+=(int increment) {
			for (size_t i = 0; i < increment; i++) {
				next();
			}
		}

		inline Iterator& operator++(int increment) {
			for (size_t i = 0; i < increment; i++) {
				next();
			}
			return *this;
		}
	private:
		bool _endReached;
	};

	friend class ArrayList<T>::Iterator;
	
	ArrayList(size_t capacity = 0) {
		setup(nullptr, 0, capacity);
	}

	ArrayList(T* items, size_t count) {
		setup(items, count, count);
	}

	template<size_t N> ArrayList(T (&items)[N]) {
		setup(items, N, N);
	}
	
	ArrayList(ArrayList<T>& collection, bool sameCapacity = false) {
		setup(collection._head, collection._size, sameCapacity ? collection._capacity : collection._size);
	}

	ArrayList(const ArrayList<T>& copy) {
		setup(copy._head, copy._size, copy._capacity);
	}

	virtual ~ArrayList() {
		free(_head);
	}

	Iterator begin() {
		return Iterator(_head, _head + _size);
	}

	Iterator reverse_begin() {
		return Iterator(_head - 1, _head + _size + 1);
	}

	ReverseIterator end() {
		return ReverseIterator(_head + _size, _head);
	}

	ReverseIterator reverse_end() {
		return ReverseIterator(_head + _size - 1, _head + 1);
	}

	inline size_t size() { return _size; }
	inline size_t capacity() { return _capacity; }
	inline T& operator[] (uint32_t index) { return _head[index]; }

	void push(T item) {
		push_range(&item, 1);
	}

	void push_range(T* items, size_t count) {
		if (_size >= _capacity) {
			set_capacity(_capacity + count);
		}
		_size += count;
		for (size_t i = 0; i < count; i++) {
			_head[_size - count + i] = items[i];
		}
	}

	void insert(T item, uint32_t index) {
		ENSURE(index >= 0 && index < _size);
		if (_size >= _capacity) {
			set_capacity(_capacity + 1);
		}
		_size++;
		ENSURE_INTMUL_NO_OVERFLOW((_size - index), sizeof(T));
		memmove(_head + index + 1, _head + index, (_size - index) * sizeof(T));
		_head[index] = item;
	}

	void remove_at(uint32_t index, bool shrink = false) {
		ENSURE(index >= 0 && index < _size);
		if (index != _size - 1) {	
			ENSURE_INTMUL_NO_OVERFLOW((_size - index), sizeof(T));
			memmove(_head + index - 1, _head + index, (_size - index) * sizeof(T));
		}
		_size--;
		if (shrink) {
			set_capacity(_size);
		}
	}

	void set_capacity(size_t capacity) {
		ENSURE(capacity >= _size);
		if (_capacity == capacity) {
			return;
		}
		_capacity = capacity;
		T* newPtr = nullptr;
		if (_capacity > 0) {
			ENSURE_INTMUL_NO_OVERFLOW(_capacity, sizeof(T));
			T* copy = (T*)Memory::alloc(_capacity * sizeof(T));
			memcpy(copy, _head, _size * sizeof(T));
			newPtr = copy;
		}
		free(_head);
		_head = newPtr;
	}

	void clear(bool shrink = true) {
		_size = 0;
		if (shrink) {
			set_capacity(0);
		}
	}

	
private:
	void setup(T* items, size_t itemCount, size_t capacity) {
		_size = 0;
		_head = nullptr;
		if (items != nullptr) {
			push_range(items, itemCount);
			if (capacity > itemCount) {
				set_capacity(capacity);
			}
		}
		else {
			set_capacity(capacity);
		}
	}

	T* _head;
	size_t _size;
	size_t _capacity;
};

#endif // __ARRAYLIST_GUARD__
