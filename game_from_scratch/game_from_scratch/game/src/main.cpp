
#include <common/windows/console.h>
#include <common/system/system.h>
#include <common/collections/collections.h>
#include <iostream>
#include <vector>
#include <list>

int main(int argc, char** argv) {
	
	

	String strA = "Hallo, hoe gaat het ermee?";
	const char* native = "Hallo, hoe gaat het ermee?";

	std::cout << strA.c_str() << std::endl;
	printf(strA.c_str()); 
	std::cout << std::endl;
	
	String strB = "Ik ben B";

	String strC = strB;
	String efef = "ROBERT ZEGT: " + strC + " <- hallo";
	
	//efef.append("Je moeder");
	printf(efef.c_str());
	
	/*ArrayList<int> ints = ArrayList<int>();
	ints.push(1);
	ints.push(2);
	ints.push(3);

	FOREACH(item, ints) {
		std::cout << *item << std::endl;
	}
	
	REVERSE_FOREACH(item, ints) {
		std::cout << *item << std::endl;
	}
	*/
	
	ArrayList<int> ints = ArrayList<int>();
	String strr = String::empty();
	int t = 0;
	//efef.clear();
	while(true) {
		printf(efef.c_str());
		//printf("\n");
		efef.append("A");
		efef.clear();
	}
	return 0;
}