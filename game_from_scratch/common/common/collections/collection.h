#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include <common/system/system.h>
#include <common/system/object.h>
#include <common/diagnostics/assertion.h>

#define reverse_foreach(iter, collection) for(auto iter = collection.reverse_end(); iter != collection.reverse_begin(); --iter) 
#define reverse_foreach_skip(iter, collection, skip) for(auto iter = collection.reverse_end(); iter != collection.reverse_begin(); iter -= (skip + 1)) 
#define foreach(iter, collection) for(auto iter = collection.begin(); iter != collection.end(); ++iter)
#define foreach_skip(iter, collection, skip) for(auto iter = collection.begin(); iter != collection.end(); iter += (skip + 1))

namespace Common {
	template<class T> class COMMON Collection : public Object {
	public:
		class COMMON CollectionBaseIterator {
		public:
			CollectionBaseIterator(const Collection<T>& collection) {
				this->_head = collection.head();
				this->_tail = collection.head() + collection.size();
				this->_current = this->_head;
			}

			CollectionBaseIterator(const T* head, const T* tail) {
				this->_head = head;
				this->_tail = tail;
				this->_current = head;
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
				_endReached = false;
			}

			Iterator(const T* head, const T* tail) : CollectionBaseIterator(head, tail) {
				_endReached = false;
			}

			inline Iterator operator-(int decrement) {
				return Iterator(CollectionBaseIterator::_head - decrement, CollectionBaseIterator::_tail);
			}

			inline Iterator operator+(int increment) {
				return Iterator(CollectionBaseIterator::_head + increment, CollectionBaseIterator::_tail);
			}

			inline void operator+=(int increment) {
				for (size_t i = 0; i < increment; ++i) {
					next();
				}
			}

			inline Iterator& operator++() {
				next();
				return *this;
			}

			inline Iterator operator++(int) {
				Iterator result(*this);
				++(*this);
				return result;
			}

		protected:
			virtual const T* next() override {
				ensure(!_endReached && "Attempting to iterate past the end of the collection");
				if (CollectionBaseIterator::_current + 1 == CollectionBaseIterator::_tail) {
					_endReached = true;
				}
				return ++CollectionBaseIterator::_current;
			}

		private:
			bool _endReached;
		};

		class COMMON ReverseIterator : public CollectionBaseIterator {
		public:
			ReverseIterator(const Collection<T>& collection) : CollectionBaseIterator(collection) {
				_beginReached = false;
			}

			ReverseIterator(const T* head, const T* tail) : CollectionBaseIterator(head, tail) {
				_beginReached = false;
			}

			inline void operator--() {
				next();
			}

			inline void operator-=(int decrement) {
				for (size_t i = 0; i < decrement; ++i) {
					next();
				}
			}

			inline ReverseIterator& operator--(int decrement) {
				for (size_t i = 0; i < decrement; ++i) {
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
			const T* next() override {
				ensure(!_beginReached && "Attempting to iterate backwards past the beginning of the collection");
				if (CollectionBaseIterator::_current - 1 == CollectionBaseIterator::_head) {
					_beginReached = true;
				}
				return --CollectionBaseIterator::_current;
			}

		private:
			bool _beginReached;
		};


	public:
		virtual ~Collection<T>() { }
		virtual size_t size() const = 0;
		virtual const T* head() const = 0;
	};
}
#endif // __COLLECTION_GUARD__
