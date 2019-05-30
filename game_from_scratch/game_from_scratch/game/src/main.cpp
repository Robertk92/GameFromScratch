#pragma comment(lib, "common.lib")

#include <common/system/system.h>
#include <common/platform/platform_dialogue.h>
#include <common/collections/collections.h>
#include <common/diagnostics/assertion.h>
#include <stdio.h>


using namespace Common;



int main(int argc, char** argv) {
	
	Out::log("Welcome.");
	int t = 0;
	int b = 1;

	ensure(t == b && "T is niet B");

	getchar();
	return 0;
}