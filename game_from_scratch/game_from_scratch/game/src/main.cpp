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
		MemberDelegate<TestMember, String&> del = MemberDelegate<TestMember, String&>();
		del.bind(this, &TestMember::test);
		del.bind(this, &TestMember::test);
		String str = "Ik vind het allemaal heelaaml hartstikke mooi";
		del.invoke(str);
	}

	void test(String& t) {
		Out::log(t);
	}
};

void hh(int d) {
	Out::log(Convert::to_string(d));
}

int main(int argc, char** argv) {
	Out::log("Welcome.");

	WindowOptions options = WindowOptions();
	options.width = 1280;
	options.height = 720;
	options.title = "Game from Scratch";
	
	GlobalDelegate<int> globDel = GlobalDelegate<int>();
	globDel.bind(hh);
	globDel.invoke(4);

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