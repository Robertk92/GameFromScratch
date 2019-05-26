
#include "windows/console.h"
#include "common/common.h"
#include <iostream>

struct LargeBlock {
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	int j;
	int k;
	int l; int m; int n; int o; int p; int q; int r; int s; int t; int u; int v; int w; int x; int y; int z;
};

int main(int argc, char** argv) {
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	//Console::writeln("Hello");
	
	List<LargeBlock> integers = List<LargeBlock>();
	
	integers.SetCapacity(200000000);
	//integers.SetCapacity(0);

	while (true) {
		
		
	}
	return 0;
}