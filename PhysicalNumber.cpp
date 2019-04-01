#include "PhysicalNumber.h"
using namespace ariel;
PhysicalNumber::PhysicalNumber(double _value, Unit::length _unit) :_value(_value)
{
	this->_len = _unit;
}

PhysicalNumber::PhysicalNumber(double _value, Unit::mass _unit) : _value(_value)
{
	this->_mass = _unit;
}

PhysicalNumber::PhysicalNumber(double _value, Unit::time _unit) : _value(_value)
{
	this->_time = _unit;
}

const PhysicalNumber PhysicalNumber::operator-() const
{
	return *this; 
	// TODO: insert return statement here
}

const PhysicalNumber PhysicalNumber::operator+() const
{
	return *this;
	// TODO: insert return statement here}
}
const PhysicalNumber & PhysicalNumber::operator+(const PhysicalNumber & other) const
{
	return *this;
	// TODO: insert return statement here}
}
const PhysicalNumber & PhysicalNumber::
operator-(const PhysicalNumber & other) const
{
	return *this;
	// TODO: insert return statement here}
}
PhysicalNumber & PhysicalNumber::operator+=(const PhysicalNumber & other)
{
	return *this;
	//TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator-=(const PhysicalNumber & other)
{
	return *this;
	//	TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator=(const PhysicalNumber & other)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator++(int)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator++()
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator--(int)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator--()
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator*=(const PhysicalNumber & other)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber & PhysicalNumber::operator/=(const PhysicalNumber & other)
{
	return *this;
	// TODO: insert return statement here
}

bool operator==(const PhysicalNumber & p1, const PhysicalNumber & p2)
{
	return false;
}

bool operator<(const PhysicalNumber & p1, const PhysicalNumber & p2)
{
	return false;
}

std::ostream & operator<<(std::ostream & os, const PhysicalNumber & other)
{
	return os;
}

std::istream & operator>>(std::istream & is, PhysicalNumber & other)
{
	return is;
}
