#pragma comment(lib, "common.lib")

#include <common/system/system.h>
#include <common/platform/platform_window.h>
#include <stdio.h>
#include <string>
using namespace Common;

int main(int argc, char** argv) {
	
	Out::log("Welcome.");
	int t = 0;
	int b = 1;

	String tg = "Hallo";
	
	WindowOptions options = WindowOptions();
	options.width = 1280;
	options.height = 720;
	options.title = "Game from Scratch";
	
	PlatformWindow window = PlatformWindow(options);
	
	
	return 0;
}