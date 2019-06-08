#include <game/core/game.h>
#include <game/worlds/worlds.h>

using namespace Blitwave;

Blitwave::GameSettings Game::game_settings() {
	return GameSettings::default_settings();
}

Blitwave::ArrayList<World*> Game::register_worlds() {
	ArrayList<World*> worlds = ArrayList<World*>();
	worlds.push(new TestWorld());
	return worlds;
}

UInt32 Game::first_world() {
	return 0;
}

void Game::setup() {

}
