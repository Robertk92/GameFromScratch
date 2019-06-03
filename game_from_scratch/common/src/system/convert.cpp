#include <common/system/convert.h>
#include <common/collections/string.h>
#include <stdio.h>
#include <stdint.h>

Common::String Common::Convert::to_string(Int32 value) {
	char vOut[12];
	_itoa_s(value, vOut, sizeof(vOut), 10);
	return String(vOut);
}

Common::String Common::Convert::to_string(Int16 value) {
	char vOut[7];
	_itoa_s(value, vOut, sizeof(vOut), 10);
	return String(vOut);
}

Common::String Common::Convert::to_string(Int8 value) {
	char vOut[2] = { value, 0 };
	return String(vOut);
}

Common::String Common::Convert::to_string(UInt32 value) {
	char vOut[11];
	_ultoa_s(value, vOut, sizeof(vOut), 10);
	return String(vOut);
}

Common::String Common::Convert::to_string(UInt16 value) {
	char vOut[6];
	_ultoa_s(value, vOut, sizeof(vOut), 10);
	return String(vOut);
}

Common::String Common::Convert::to_string(UInt8 value) {
	char vOut[2] = { static_cast<char>(value), 0 };
	return String(vOut);
}

Common::String Common::Convert::to_string(float value) {
	char vOut[17];
	_gcvt_s(vOut, sizeof(vOut), value, 8);
	return String(vOut);
}

Common::String Common::Convert::to_string(double value) {
	char vOut[26];
	_gcvt_s(vOut, sizeof(vOut), value, 17);
	return String(vOut);
}

Common::String Common::Convert::to_string(bool value) {
	return value ? String::true_str() : String::false_str();
}

