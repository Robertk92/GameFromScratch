#ifndef __TEST_WORLD_GUARD__
#define __TEST_WORLD_GUARD__

#include <blitwave/framework/world.h>
using namespace Blitwave;

class TestWorld : public World {
public:
	void setup() override;
};

#endif // __TEST_WORLD_GUARD__
