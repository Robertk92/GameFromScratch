#include <common/system/system.h>
#include <common/collections/string.h>
#include <common/system/convert.h>
#include <stdio.h>

void Common::Out::log_no_newline(const String& str) {
	log_internal(str.c_str());
}

void Common::Out::log(const String& str) {
	log_internal((str + String::new_line()).c_str());
}

void Common::Out::error(const String& errStr) {
	error(errStr.c_str());
}

void Common::Out::error(const char* err, const char* file, int line) {
	String str = String(err);
	str += " in file: " + String(file) + " line " + Convert::ToString(line) + String::new_line();
	fprintf(stderr, str.c_str());
}

void Common::Out::error(const char* err) {
	fprintf(stderr, err);
}

void Common::Out::log_internal(const char* chars) {
	printf(chars);
}
