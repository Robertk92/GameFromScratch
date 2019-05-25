
#include "windows/console.h"
#include "common/common.h"
#include <iostream>
int main(int argc, char** argv) {
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	//Console::writeln("Hello");
	List<int> integers = List<int>();
	
	
	for (int i = 0; i < 100000; i++)
	{
		integers.SetCapacity(i);
	}

	// Issue: this doesnt clear the memory
	integers.SetCapacity(0);

	integers.TestPrint();
	
	while (true) {
		
		
	}
	return 0;
}