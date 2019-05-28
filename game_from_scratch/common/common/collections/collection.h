#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include <common/system/object.h>

#define REVERSE_FOREACH(it, collection) for(auto it = collection.reverse_end(); it != collection.reverse_begin(); --it) 
#define FOREACH(it, collection) for(auto it = collection.begin(); it != collection.end(); ++it)

template<class T> class COMMON Collection : public Object {
public:
	class COMMON CollectionBaseIterator {
	public:
		CollectionBaseIterator(const Collection<T>& collection) {
			this->_head = collection.head();
			this->_tail = collection.tail();
		}

		CollectionBaseIterator(const T* head, const T* tail) {
			this->_head = head;
			this->_tail = tail;
		}

		inline const T& operator*() const {
			return *_current;
		}

		inline const T* operator->() const {
			return _current;
		}

		inline CollectionBaseIterator& operator=(const CollectionBaseIterator& rhs) {
			_current = rhs._current;
			return *this;
		}

		inline bool operator==(const CollectionBaseIterator& rhs) {
			return this->_current == rhs._current;
		}

		inline bool operator!=(const CollectionBaseIterator& rhs) {
			return this->_current != rhs._current;
		}

	protected:
		virtual const T* next() = 0;
		
		const T* _head;
		const T* _tail;
		const T* _current;
	};

	class COMMON Iterator : public CollectionBaseIterator {
	public:
		Iterator(const Collection<T>& collection) : CollectionBaseIterator(collection) {
			this->_head = collection.head();
			this->_tail = collection.tail();
		}

		Iterator(const T* head, const T* tail) : CollectionBaseIterator(head, tail) {
			CollectionBaseIterator::_current = head;
		}

		inline Iterator operator-(int decrement) {
			return Iterator(CollectionBaseIterator::_head - decrement, CollectionBaseIterator::_tail);
		}

		inline Iterator operator+(int increment) {
			return Iterator(CollectionBaseIterator::_head + increment, CollectionBaseIterator::_tail);
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

	protected:
		const T* next() = 0;
	};

	class COMMON ReverseIterator : public CollectionBaseIterator {
	public:
		ReverseIterator(const Collection<T>& collection) : CollectionBaseIterator(collection) {
			this->_head = collection.head();
			this->_tail = collection.tail();
		}

		ReverseIterator(const T* head, const T* tail) : CollectionBaseIterator(head, tail) {
			CollectionBaseIterator::_current = head;
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
			return ReverseIterator(CollectionBaseIterator::_head - decrement, CollectionBaseIterator::_tail);
		}

		inline ReverseIterator operator+(int increment) {
			return ReverseIterator(CollectionBaseIterator::_head + increment, CollectionBaseIterator::_tail);
		}

	protected:
		const T* next() = 0;
	};

public:
	virtual const T* head() const = 0;
	virtual const T* tail() const = 0;
};

#endif // __COLLECTION_GUARD__
