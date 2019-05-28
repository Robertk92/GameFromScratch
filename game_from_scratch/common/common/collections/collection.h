#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include <common/system/object.h>

#define REVERSE_FOREACH(it, collection) for(auto it = collection.reverse_end(); it != collection.reverse_begin(); --it) 
#define FOREACH(it, collection) for(auto it = collection.begin(); it != collection.end(); ++it)

template<class T> class COMMON Collection : public Object {
public:
	class COMMON Iterator {
	public:
		Iterator(const T* head, const T* tail) {
			this->_head = head;
			this->_tail = tail;
		}

		inline const T& operator*() const {
			return *_current;
		}

		inline const T* operator->() const {
			return _current;
		}

		inline Iterator& operator=(const Iterator& rhs) {
			_current = rhs._current;
			return *this;
		}

		inline bool operator==(const Iterator& rhs) {
			return this->_current == rhs._current;
		}

		inline bool operator!=(const Iterator& rhs) {
			return this->_current != rhs._current;
		}

	protected:
		virtual const T* next() = 0;

		const T* _head;
		const T* _tail;
		const T* _current;
	};
};

#endif // __COLLECTION_GUARD__
