#ifndef __STRING_GUARD__
#define __STRING_GUARD__

#include <common/system/system.h>
#include <common/collections/arraylist.h>

class COMMON String : public ArrayList<char> {
protected:
	
/*
public:
	String(char* items = nullptr, size_t capacity = 0) : Collection<char>(items, capacity) {

	}

	//void Append(String str) { Collection<char>::Push(character); }
	void RemoveAt(uint32_t index, bool shrink = false) { Collection<char>::RemoveAt(index, shrink); }
	void Clear(bool shrink = false) { Collection<char>::Clear(shrink); }
	void SetCapacity(size_t capacity) { Collection<char>::SetCapacity(capacity); }

	void operator=(const char* str) {

	}

private:*/
	
};

#endif
