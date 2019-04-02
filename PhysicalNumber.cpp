#include "PhysicalNumber.h"
using namespace ariel;

ariel::PhysicalNumber::PhysicalNumber(double _value, Unit _type) : _value(_value), _type(_type) {}

const PhysicalNumber ariel::PhysicalNumber::operator-() const
{
	double new_value = -1 * this->_value;
	Unit new_type = this->_type;
	return PhysicalNumber(new_value, new_type);
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
/** this method is responsible to check if two inputs can do arithmetic operations **/
bool ariel::PhysicalNumber::verifier(const PhysicalNumber & input1, const PhysicalNumber & input2) const
{
	if (is_len(input1, input2) || is_mass(input1, input2) || is_time(input1, input2)) return true;
	else return false;
}

bool ariel::PhysicalNumber::is_len(const PhysicalNumber & input1, const PhysicalNumber & input2) const
{
	return true;
}

bool ariel::PhysicalNumber::is_mass(const PhysicalNumber & input1, const PhysicalNumber & input2) const
{
	return false;
}

bool ariel::PhysicalNumber::is_time(const PhysicalNumber & input1, const PhysicalNumber & input2) const
{
	return false;
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
	return os << other._value << "[" << "]";
}

std::istream & ariel::operator>>(std::istream & is, PhysicalNumber& other)
{
	return is;
}

