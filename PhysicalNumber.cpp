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

const PhysicalNumber ariel::PhysicalNumber::operator-() const
{
	return *this;
}

const PhysicalNumber ariel::PhysicalNumber::operator+() const
{
	return *this;
}

const PhysicalNumber& ariel::PhysicalNumber::operator+(const PhysicalNumber& other) const
{
	// TODO: insert return statement here
	return *this;
}

const PhysicalNumber& ariel::PhysicalNumber::operator-(const PhysicalNumber& other) const
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator=(const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator++(int)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator++()
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator--(int)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator--()
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator/(const PhysicalNumber & other)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber& ariel::PhysicalNumber::operator*(const PhysicalNumber & other)
{
	return *this;
	// TODO: insert return statement here
}

PhysicalNumber& ariel::PhysicalNumber::operator*=(const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return *this;
}

PhysicalNumber& ariel::PhysicalNumber::operator/=(const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return *this;
}

bool ariel::operator==(const PhysicalNumber& p1, const PhysicalNumber& p2)
{
	return false;
}

bool ariel::operator<(const PhysicalNumber& p1, const PhysicalNumber& p2)
{
	return false;
}

std::ostream & ariel::operator<<(std::ostream & os, const PhysicalNumber& other)
{
	// TODO: insert return statement here
	return os;
}

std::istream & ariel::operator>>(std::istream & is, PhysicalNumber& other)
{
	// TODO: insert return statement here
	return is;
}

