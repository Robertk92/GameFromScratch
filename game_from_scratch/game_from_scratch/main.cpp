#pragma comment(lib, "blitwave.lib")

#include <blitwave/engine.h>
#include <game/core/game.h>
using namespace Blitwave;

int main(int argc, char** argv) {
	Engine::create_game_and_run<Game>();
	return 0;
}