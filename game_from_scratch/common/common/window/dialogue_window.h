#ifndef __DIALOGUE_WINDOW_GUARD__
#define __DIALOGUE_WINDOW_GUARD__

#include <common/system/system.h>

namespace Common {
	enum COMMON EPlatformDialogueType {
		Info,
		Warning,
		Error
	};

	class String;
	class COMMON DialogueWindow {
	public:
		static void show(const char* msg, const EPlatformDialogueType& dialogueType = EPlatformDialogueType::Info);
		static void show(String& msg, const EPlatformDialogueType& dialogueType = EPlatformDialogueType::Info);

	private:
		static void show_internal(String& msg, const EPlatformDialogueType& dialogueType);
	};
}

#endif //__DIALOGUE_WINDOW_GUARD__
