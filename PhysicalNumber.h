#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
namespace ariel {
	class PhysicalNumber {
		double _value;

	public:
		PhysicalNumber(double _value, Unit::length);
		PhysicalNumber(double _value, Unit::mass);
		PhysicalNumber(double _value, Unit::time);

	};
}

#endif
