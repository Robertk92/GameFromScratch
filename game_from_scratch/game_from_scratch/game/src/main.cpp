
#include <common/windows/console.h>
#include <common/system/system.h>
#include <common/collections/collections.h>
#include <iostream>

int main(int argc, char** argv) {
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	//Console::writeln("Hello");
	//Memory::Malloc(10000000000);

	int items[] = { 1, 2, 3, 4 };
	List<int> myList = List<int>(items);
	List<int> list2 = List<int>(myList);
	list2.Remove(2);
	foreach(item, list2) {
		std::cout << *item << std::endl;
	}
	std::cout << "size = " << list2.Size() << std::endl;
	

	while (true) {
			
	}
	return 0;
}