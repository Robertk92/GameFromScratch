
#include <common/windows/console.h>
#include <common/system/system.h>
#include <common/collections/collections.h>
#include <iostream>

int main(int argc, char** argv) {
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	//Console::writeln("Hello");
	//Memory::Malloc(10000000000);

	
	List<int> ints = List<int>();
	int t = 0;
	while (true) {
		ints.Push(0);
		ints.Clear();
	}
	return 0;
}