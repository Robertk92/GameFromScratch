#include <common/window/dialogue_window.h>
#include <common/collections/string.h>

void Common::DialogueWindow::show(const char* msg, const EPlatformDialogueType& dialogueType /*= EPlatformDialogueType::Info*/) {
	String msgStr = String(msg);
	show_internal(msgStr, dialogueType);
}

void Common::DialogueWindow::show(String& msg, const EPlatformDialogueType& dialogueType /*= EPlatformDialogueType::Info*/) {
	show_internal(msg, dialogueType);
}

#if defined(_WIN32) 
	#include <common/platform_utility/win_utility.h>
	void Common::DialogueWindow::show_internal(String& msg, const EPlatformDialogueType& dialogueType) {
		switch (dialogueType) {
			case Info: {
				msg.prepend("Message: ");
				const char* msg_c = msg.c_str();
				const wchar_t* wcMsg = WinUtility::to_wchar_ptr(msg_c);
				MessageBox(NULL, wcMsg, (LPCWSTR)L"Message", MB_OK | MB_ICONINFORMATION);
				break;
			}
			case Warning: {
				msg.prepend("Warning: ");
				const char* msg_c = msg.c_str();
				const wchar_t* wcMsg = WinUtility::to_wchar_ptr(msg_c);
				MessageBox(NULL, wcMsg, (LPCWSTR)L"Warning", MB_OK | MB_ICONWARNING);
				break;
			}
			case Error: {
				msg.prepend("Error: ");
				const char* msg_c = msg.c_str();
				const wchar_t* wcMsg = WinUtility::to_wchar_ptr(msg_c);
				MessageBox(NULL, wcMsg, (LPCWSTR)L"Error", MB_OK | MB_ICONERROR);
				break;
			}
		}
	}
#elif defined(__APPLE__)
	void Common::DialogueWindow::show_internal(const String& msg, const EPlatformDialogueType& dialogueType) { /*TODO_APPLE: implement apple messagebox*/ }
#elif defined(__linux__)
	void Common::DialogueWindow::show_internal(const String& msg, const EPlatformDialogueType& dialogueType) { /*TODO_LINUX: implement linux messagebox*/ }
#else 
	void Common::DialogueWindow::show_internal(const String& msg, const EPlatformDialogueType& dialogueType) { }
#endif



