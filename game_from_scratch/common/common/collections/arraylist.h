#ifndef __ARRAYLIST_GUARD__
#define __ARRAYLIST_GUARD__

#include <common/system/system.h>
#include <common/system/memory.h>
#include <common/collections/collection.h>
#include <common/diagnostics/assertion.h>
#include <common/collections/string.h>

namespace Common {
	template<class T> class COMMON ArrayList : public Collection<T> {
		using BaseIterator = Collection<T>::Iterator;
		using BaseReverseIterator = Collection<T>::ReverseIterator;
	public:
		class COMMON Iterator : public BaseIterator {
		public:
			Iterator(const Collection<T>& collection) : BaseIterator(collection) { }
			Iterator(const T* head, const T* tail) : BaseIterator(head, tail) { }
		};

		class COMMON ReverseIterator : public BaseReverseIterator {
		public:
			ReverseIterator(const Collection<T>& collection) : BaseReverseIterator(collection) { }
			ReverseIterator(const T* head, const T* tail) : BaseReverseIterator(head, tail) { }
		};

		ArrayList() {
			setup(nullptr, 0, 0);
		}

		ArrayList(size_t capacity) {
			setup(nullptr, 0, capacity);
		}

		ArrayList(const T* items, size_t count) {
			setup(items, count, count);
		}

		template<size_t N> ArrayList(T(&items)[N]) {
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

		BaseIterator begin() {
			return Iterator(_head, _head + _size);
		}

		BaseIterator reverse_begin() {
			return Iterator(_head - 1, _head + _size + 1);
		}

		BaseReverseIterator end() {
			return ReverseIterator(_head + _size, _head);
		}

		BaseReverseIterator reverse_end() {
			return ReverseIterator(_head + _size - 1, _head + 1);
		}

		inline size_t size() { return _size; }
		inline size_t capacity() { return _capacity; }
		inline T& operator[] (uint32_t index) { return _head[index]; }

		const T* head() const override {
			return _head;
		}

		size_t size() const override {
			return _size;
		}

		void push(T item) {
			push_range(&item, 1);
		}

		void push_range(const T* items, size_t count) {
			if (_size >= _capacity) {
				set_capacity(_capacity + count);
			}
			_size += count;
			for (size_t i = 0; i < count; i++) {
				_head[_size - count + i] = items[i];
			}
		}

		void insert(T item, uint32_t index) {
			ensure(index >= 0 && index < _size);
			if (_size >= _capacity) {
				set_capacity(_capacity + 1);
			}
			++_size;
			ensure_uintmul_no_overflow((_size - index), sizeof(T));
			memmove(_head + index + 1, _head + index, (_size - index) * sizeof(T));
			_head[index] = item;
		}

		void remove_at(uint32_t index, bool shrink = false) {
			ensure(index >= 0 && index < _size);
			if (index != _size - 1) {
				ensure_uintmul_no_overflow((_size - index), sizeof(T));
				memmove(_head + index - 1, _head + index, (_size - index) * sizeof(T));
			}
			--_size;
			if (shrink) {
				set_capacity(_size);
			}
		}

		void set_capacity(size_t capacity) {
			ensure(capacity >= _size);
			if (_capacity == capacity) {
				return;
			}
			_capacity = capacity;
			T* newPtr = nullptr;
			if (_capacity > 0) {
				ensure_uintmul_no_overflow(_capacity, sizeof(T));
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

	protected:
		void setup(const T* items, size_t itemCount, size_t capacity) {
			_size = 0;
			_capacity = 0;
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

		size_t _size;
		size_t _capacity;
		T* _head;
	};
}

#endif // __ARRAYLIST_GUARD__
