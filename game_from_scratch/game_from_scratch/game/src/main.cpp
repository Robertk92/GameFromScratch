#pragma comment(lib, "common.lib")

#include <common/system/system.h>
#include <common/window/window.h>
#include <common/threading/thread.h>
#include <stdio.h>
#include <string>
#include <common/system/convert.h>
#include "common/window/dialogue_window.h"
#include <common/system/delegate.h>
#include <functional>
using namespace Common;

class TestMember {
public:
	TestMember() {
		MemberDelegate<TestMember> del = MemberDelegate<TestMember>();
		
		del.bind(this, &TestMember::test);
		del.bind(this, &TestMember::test2);
		del.invoke();
	}

	void test2() {
		Out::log("test 2");
	}

	void test() {
		Out::log("test");
	}
};

int main(int argc, char** argv) {
	Out::log("Welcome.");
	
	WindowOptions options = WindowOptions();
	options.width = 1280;
	options.height = 720;
	options.title = "Game from Scratch";
	
	Window window = Window(options);
	TestMember t = TestMember();

	WindowMessage msg;
	while (window.is_open()) {
		if (window.poll_message(&msg)) {
			Out::log(Convert::to_string(msg.type));
		}
		window.draw();
		Thread::sleep_ms(10);
	}
	
	return 0;
}