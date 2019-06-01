#pragma comment(lib, "common.lib")

#include <common/system/system.h>
#include <common/window/window.h>
#include <common/threading/thread.h>
#include <stdio.h>
#include <string>
#include <common/system/convert.h>
#include "common/window/dialogue_window.h"

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
	
	Window window = Window(options);
	
	WindowMessage msg;
	while (window.is_open()) {
		if (window.poll_message(&msg)) {
			Out::log(Convert::to_string(msg.type));
		}
		window.draw();
		Thread::sleep_ms(100);
	}
	
	return 0;
}