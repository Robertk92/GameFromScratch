#pragma comment(lib, "blitwave.lib")

#include <blitwave/engine.h>
#include <game/core/game.h>

int main(int argc, char** argv) {
	engine()->run<Game>();
	return 0;
}