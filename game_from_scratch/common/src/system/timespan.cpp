#include <common/system/timespan.h>
#include <math.h>

Common::Timespan::Timespan(UInt32 milliseconds) {
	this->_ms = milliseconds;
}

Common::Timespan Common::Timespan::FromSeconds(double seconds) {
	return Timespan(ceil(seconds * 1000.0));
}

const UInt32 Common::Timespan::milliseconds() const {
	return _ms;
}

const double Common::Timespan::seconds() {
	return ((double)_ms) / 1000.0;
}

bool Common::Timespan::operator>(const Timespan& rhs) {
	return _ms > rhs._ms;
}

bool Common::Timespan::operator<(const Timespan& rhs) {
	return _ms < rhs._ms;
}

bool Common::Timespan::operator!=(const Timespan& rhs) {
	return _ms != rhs._ms;
}

bool Common::Timespan::operator==(const Timespan& rhs) {
	return _ms == rhs._ms;
}

bool Common::Timespan::operator<=(const Timespan& rhs) {
	return _ms <= rhs._ms;
}

bool Common::Timespan::operator>=(const Timespan& rhs) {
	return _ms >= rhs._ms;
}

