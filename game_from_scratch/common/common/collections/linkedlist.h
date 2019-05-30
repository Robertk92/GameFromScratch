#ifndef __LIST_GUARD__
#define __LIST_GUARD__

#include <common/system/system.h>
#include <common/collections/collection.h>

namespace Common {
	template<class T> class COMMON LinkedList : public Collection<T> {
	public:

		virtual ~LinkedList() {

		}

	};
}

#endif