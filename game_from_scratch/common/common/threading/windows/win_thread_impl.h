#ifndef __WIN_THREAD_IMPL_GUARD__
#define __WIN_THREAD_IMPL_GUARD__
#if defined(_WIN32)

#include <common/threading/thread_impl.h>
#include <windows.h>

namespace Common {
	class COMMON WinThreadImpl final : public ThreadImpl {
	public:
		WinThreadImpl();
		~WinThreadImpl();

	private:
		HANDLE _threadHandle;
		DWORD _threadId;
	};
}

#endif // defined(_WIN32)
#endif // !__WIN_THREAD_IMPL_GUARD__

