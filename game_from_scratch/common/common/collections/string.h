#ifndef __STRING_GUARD__
#define __STRING_GUARD__

#include <common/system/system.h>
#include <common/system/memory.h>
#include <common/collections/collection.h>
#include <common/diagnostics/assertion.h>
#include <string.h> // C header 

#define EMPTY_C_STR "\0"

class COMMON String : public Collection<char> {
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

	String() { 
		setup(EMPTY_C_STR);
	}

	String(const char* chars, size_t capacity = 0) {
		setup(chars);
	}

	template<size_t N> String(char(&items)[N]) {
		setup(items);
	}

	String(const String& other) {
		setup(other._head);
	}

	virtual ~String() {
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

	size_t size() const override {
		return _size;
	}

	const char* head() const override {
		return _head;
	}

	String& append(const String& str) {
		append(str.c_str());
		return *this;
	}

	String& append(const char* chars) {
		add_chars(chars, true);
		return *this;
	}

	String& prepend(const String& str) {
		prepend(str.c_str());
		return *this;
	}

	String& prepend(const char* chars) {
		add_chars(chars, false);
		return *this;
	}

	static String empty() {
		return String(EMPTY_C_STR);
	}

	const char* c_str() const {
		if (_head == nullptr) {
			return EMPTY_C_STR;
		}
		return _head;
	}

	inline String operator=(const String& rhs) {
		return String(rhs);
	}

	/*inline String& operator=(const char* chars) {
		set(chars);
		return *this;
	}*/

	inline String& operator+=(const String& str) {
		return append(str);
	}

	inline String& operator+(const char* str) {
		return append(str);
	}

	inline friend String operator+(String& lhs, String& rhs) {
		String combined = lhs;
		combined.append(rhs);
		return combined;
	}

	inline friend String operator+(const char* lhs, String& rhs) {
		String str = String(lhs);
		str.append(rhs);
		return str;
	}

private:
	void setup(const char* data) {
		_head = nullptr;
		_size = 0;
		set_chars(data);
	}

	void set_chars(const char* chars) {
		if (_head != nullptr) {
			free(_head);
		}
		_size = strlen(chars);
		_head = (char*)Memory::alloc(_size * sizeof(char) + 1);
		strncpy_s(_head, _size + 1, chars, _TRUNCATE);
	}

	void add_chars(const char* chars, bool append) {
		size_t lhsSize = strlen(chars);
		size_t combinedSize = lhsSize + size();
		char* combined = (char*)Memory::alloc(combinedSize + 2);
		if (append) {
			strncpy_s(combined, size() + 1, c_str(), _TRUNCATE);
			strncpy_s(combined + size(), lhsSize + 1, chars, _TRUNCATE);
		}
		else {
			strncpy_s(combined, lhsSize + 1, chars, _TRUNCATE);
			strncpy_s(combined + lhsSize, size() + 1, c_str(), _TRUNCATE);
		}
		set_chars(combined);
		free(combined);
	}

private:
	size_t _size;
	char* _head;
};

#endif //__STRING_GUARD__
