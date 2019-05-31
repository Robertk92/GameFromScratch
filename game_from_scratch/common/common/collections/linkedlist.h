#ifndef __LIST_GUARD__
#define __LIST_GUARD__

#include <common/system/system.h>
#include <common/collections/collection.h>

namespace Common {
	template<class T> class COMMON LinkedListNode {
	public:
		LinkedListNode(const T* self, const T* next, const T* prev) {
			this->_next = next;
			this->_prev = prev;
			this->_self = self;
		}

		const T* next() const { return _next; }
		const T* previous() const { return _prev; }
		const T* self() const { return _self; }
	private:
		const T* _self;
		const T* _next;
		const T* _prev;
	};

	template<class T> class COMMON LinkedList : public Collection<T> {
		using BaseIterator = Collection<T>::Iterator;
		using BaseReverseIterator = Collection<T>::ReverseIterator;
	public:
		class COMMON Iterator : public BaseIterator {
		public:
			Iterator(const Collection<T>& collection) : BaseIterator(collection) { }
			Iterator(const T* head, const T* tail) : BaseIterator(head, tail) { }

		protected:
			const T* next() override {
				ensure(_head->next() != nullptr && "Attempting to iterate past the end of the collection");
				Collection<T>::CollectionBaseIterator::_current = _head->next();
			}
		};

		class COMMON ReverseIterator : public BaseReverseIterator {
		public:
			ReverseIterator(const Collection<T>& collection) : BaseReverseIterator(collection) { }
			ReverseIterator(const T* head, const T* tail) : BaseReverseIterator(head, tail) { }

			const T* next() override {
				ensure(_head->previous() != nullptr && "Attempting to iterate backwards past the beginning of the collection");
				Collection<T>::CollectionBaseIterator::_current = _head->previous();
			}
		};
		
		LinkedList() {
			not_implemented();
		}

		virtual ~LinkedList() {

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

		
		const T* head() const override {
			return _head->self();
		}

		Size size() const override {
			return _size;
		}

	private:
		LinkedListNode<T>* _head;
		LinkedListNode<T>* _tail;
		Size _size;
	};
}

#endif