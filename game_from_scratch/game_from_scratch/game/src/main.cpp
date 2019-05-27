
#include <common/windows/console.h>
#include <common/system/system.h>
#include <common/collections/collections.h>
#include <iostream>

int main(int argc, char** argv) {
	//Console::writeln("Hello");
	
	ArrayList<int> test = ArrayList<int>();
	test.Push(1);
	test.Push(2);
	test.Push(3);
	for (auto it = test.Begin(); it != test.End(); it = test.Next()) {
		for (auto it = test.Begin(); it != test.End(); it = test.Next()) {
			std::cout << *it << std::endl;
		}
	}

	/*foreach(item, test)
	{
		foreach(item2, test)
		{
			std::cout << *item2 << std::endl;
		}
	}*/

	while(true) {}
	/*ArrayList<int> ints = ArrayList<int>();
	ints.Push(1);
	ints.Push(2);
	ints.Push(3);
	ints.Push(4);
	
	
	foreach(item, ints)
	{
		//std::cout << *item << std::endl;
	}
	
	while (true) {
		ints.Push(0);
		ints.Clear();
	}*/
	return 0;
}