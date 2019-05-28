#ifndef __STRING_GUARD__
#define __STRING_GUARD__

#include <common/system/system.h>
#include <common/collections/arraylist.h>
#include <string.h> // C header 

class COMMON String : public ArrayList<char> {
	using BaseIterator = Collection<char>::Iterator;
	using BaseReverseIterator = Collection<char>::ReverseIterator;
public:
	class COMMON Iterator : public BaseIterator {
	public:
		Iterator(const Collection<char>& collection) : BaseIterator(collection) { }
		Iterator(const char* head, const char* tail) : BaseIterator(head, tail) { }
	};

	class COMMON ReverseIterator : public BaseReverseIterator {
	public:
		ReverseIterator(const Collection<char>& collection) : BaseReverseIterator(collection) { }
		ReverseIterator(const char* head, const char* tail) : BaseReverseIterator(head, tail) { }
	};

	String() : ArrayList<char>() { 
		setup();
	}

	String(size_t capacity) : ArrayList<char>(capacity) { 
		setup();
	}

	String(const char* chars, size_t capacity = 0) : ArrayList<char>(chars, strlen(chars)) { 
		setup();
	}

	template<size_t N> String(char(&items)[N]) : ArrayList<char>(items) {  
		setup();
	}

	String(const String& other) : ArrayList<char>(other.c_str(), strlen(other.c_str())) {
		setup();
	}

	static const String& empty() {
		return _emptyStr;
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

	inline String operator=(const String& rhs) {
		return String(rhs);
	}

	inline String& operator=(const char* chars) {
		clear();
		push_range(chars, strlen(chars));
		return *this;
	}

	inline String& operator+=(const char* chars) {
		push_range(chars, strlen(chars));
		return *this;
	}

	inline String& operator+(const char* chars) {
		push_range(chars, strlen(chars));
		return *this;
	}

	inline friend String operator+(const char* lhs, String& rhs) {
		size_t lhsSize = strlen(lhs);
		size_t totalSize = lhsSize + rhs.size();
		char* concat = (char*)Memory::alloc(totalSize + 2);
		strncpy_s(concat, lhsSize + 1, lhs, _TRUNCATE);
		strncpy_s(concat + lhsSize, rhs.size() + 1, rhs.c_str(), _TRUNCATE);
		return String(concat);
	}

	void append(String str) {
		BROKEN("Doesnt break using it but leaves the arraylist in a broken state where size is too large next time push_items is called"); {
			size_t len = size() + str.size();
			char* concatted = (char*)Memory::alloc(len + 2);
			strncpy_s(concatted, size() + 1, c_str(), _TRUNCATE);
			strncpy_s(concatted + size(), str.size() + 1, str.c_str(), _TRUNCATE);
			clear(false);
			push_range(concatted, strlen(concatted));
		}
	}

	const char* c_str() const {
		if (_head == nullptr) {
			return _emptyCStr;
		}

		if (_cStr != nullptr) {
			free(_cStr);
		}
		_cStr = (char*)Memory::alloc(_size + 1);
		strncpy_s(_cStr, _size + 1, _head, _TRUNCATE);
		return _cStr;
	}

private:
	void setup() {
		if (_emptyCStr == nullptr) {
			_emptyCStr = (char*)Memory::alloc(sizeof(char));
			memset(_emptyCStr, 0, sizeof(char));
			_emptyStr = String(_emptyCStr);
		}
		_prevCStrSize = 0;
		_cStr = nullptr;
	}

	size_t _prevCStrSize;
	mutable char* _cStr;

	static String _emptyStr;
	static char* _emptyCStr;
};

String String::_emptyStr;
char* String::_emptyCStr;

#endif
