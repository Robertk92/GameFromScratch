#ifndef __COLLECTION_GUARD__
#define __COLLECTION_GUARD__

#include "object.h"
#include "assertion.h"
#include <iostream>


template<class T> class Collection : public Object {
public:
	Collection(int capacity = 0) {
		_size = 0;
		_data = (T*)malloc(capacity * sizeof(T)); 
	}

	virtual ~Collection() {
		delete[] _data;
	}

	void TestPrint() {
		for (int i = 0; i < _size; i++) {
			std::cout << _data[i] << std::endl;
		}
	}

protected:
	void Push(T item) {
		if (_size >= _capacity) {
			SetCapacity(_capacity + 1);
		}
		_size++;
		_data[_size - 1] = item;
	}

	void Insert(T item, int index) {
		ensure(index >= 0 && index < _size);
		if (_size >= _capacity) {
			SetCapacity(_capacity + 1);
		}
		_size++;
		memmove(_data + index + 1, _data + index,(_size - index) * sizeof(T));
		_data[index] = item;
	}

	void RemoveAt(int index, bool shrink = false) {
		ensure(index >= 0 && index < _size);
		if (index == _size - 1) {	
			_size--;
			return;
		}
		memmove(_data + index - 1, _data + index, (_size - index) * sizeof(T));
		_size--;
		if (shrink) {
			SetCapacity(_size);
		}
	}

	void SetCapacity(int capacity) {
		ensure(capacity >= _size);
		if (_capacity == capacity) {
			return;
		}
		_capacity = capacity;
		
		T* copy = (T*)malloc(_capacity * sizeof(T));
		memcpy(copy, _data, _size * sizeof(T));
		delete[] _data;
		_data = copy;
	}

	void Clear(bool shrink = false) {
		delete[] _data;
		_size = 0;
		if (shrink) {
			_capacity = 0;
			_data = nullptr;
		}
		else {
			_data = (T*)malloc(_capacity * sizeof(T));
		}
	}

private:
	int _capacity;
	int _size;
	T* _data;
};

#endif
