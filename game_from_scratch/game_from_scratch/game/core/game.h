#ifndef __GAME_GUARD__
#define __GAME_GUARD__

#include <blitwave/framework/game_interface.h>
using namespace Blitwave;
class Game : public GameInterface {
public:
	GameSettings game_settings() override;
	void setup() override;
	
};

#endif//__GAME_GUARD__
