
#include <common/windows/console.h>
#include <common/system/system.h>
#include <common/collections/collections.h>
#include <iostream>
#include <vector>

class Test {
public:
	Test(int t) {
		hallo = t;
	}
	int hallo;
};

int main(int argc, char** argv) {
	//Console::writeln("Hello");
	
	

	std::vector<Test> vec = std::vector<Test>();
	vec.push_back(Test(1));
	vec.push_back(Test(2));
	vec.push_back(Test(3));

	/*for (auto t : vec) {

	}

	for (int f : test) {
		std::cout << f << std::endl;
	}
	*/

	/*for (auto it = vec.end(); it != vec.begin(); --it) {
		std::cout << it->hallo << std::endl;
	}
*/

	
	/*REVERSE_FOREACH(it, test) {
		std::cout << it->hallo << std::endl;
	}*/

	ArrayList<Test> test = ArrayList<Test>();
	test.push(Test(1));
	test.push(Test(2));
	test.push(Test(3));

	for (auto t : test) {
		std::cout << "itautoloop: " << t.hallo << std::endl;
	}

	for (size_t i = 0; i < test.size(); i++) {
		std::cout << "itforloop: " << test[0].hallo << std::endl;
	}

	FOREACH(it, test) {
		std::cout << "it1 forward  : " << it->hallo << std::endl;
		REVERSE_FOREACH(it2, test) {
			std::cout << "it2 reverse: " << it->hallo << std::endl;
		}
	}


	/*for (auto it = test.begin(); it != test.end(); ++it) {
		std::cout << it->hallo << std::endl;
	}
	std::cout << "qwdwq" << std::endl;

	for (auto it = test.rend(); it != test.rbegin() ; --it) {
		std::cout << it->hallo << std::endl;
	}*/

	/*for (ArrayList<Test>::Iterator it = test.begin(); it != test.end(); ++it) {
		
		//std::cout << (*it).hallo << std::endl;
	}*/

	/*for (auto it = test.Begin(); it != test.End(); ++it) {
		std::cout << *it << std::endl;
	}*/

	

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