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

void Common::Out::log_err(const String& str) {
	fprintf(stderr, str.c_str());
}

void Common::Out::log_err(const char* chars) {
	log_internal(chars);
}

void Common::Out::log_internal(const char* chars) {
	fprintf(stdout, chars);
}
