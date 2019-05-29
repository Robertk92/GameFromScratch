

#include <common/windows/console.h>
#include <common/system/system.h>

#include <common/collections/collections.h>


#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	String myString = " van ";
	String hallo = ("Hoedje" + myString + "papier.");
	
	
	std::string vanStd = " van ";
	
	std::cout << hallo.c_str() << std::endl;
	while(true) {
		//std::string tt = "Hoedje" + vanStd + "papier";
		ArrayList<String> strings = ArrayList<String>();
		for (size_t i = 0; i < 10000; i++)
		{
			String s = "Hoedje" + myString + "papier";
			s += " en van karton";
			strings.push(s);
		}
		strings.clear();

		/*std::vector<std::string> stdStrings = std::vector<std::string>();
		for (size_t i = 0; i < 10000; i++)
		{
			std::string s2 = "Hoedje" + vanStd + "papier.";
			stdStrings.push_back(s2);
		}
		stdStrings.clear();*/
	}
	return 0;
}