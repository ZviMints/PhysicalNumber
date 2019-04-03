#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
using namespace ariel;
#include <iostream>
namespace ariel {
	class PhysicalNumber {

		double _value;
		Unit _type;

	public:
		// Constructors:
		PhysicalNumber(double, Unit);

		// arithmetic operators
		PhysicalNumber operator-();
		PhysicalNumber operator+();
		PhysicalNumber operator+(const PhysicalNumber&);
		PhysicalNumber operator-(const PhysicalNumber&);
		PhysicalNumber& operator+=(const PhysicalNumber&);
		PhysicalNumber& operator-=(const PhysicalNumber&);
		PhysicalNumber& operator=(const PhysicalNumber&);

		// 6 comparison operators
		friend bool operator==(const PhysicalNumber&, const PhysicalNumber&);
		friend bool operator<(const PhysicalNumber&, const PhysicalNumber&); 
		friend bool operator!=(const PhysicalNumber&, const PhysicalNumber&);
		friend bool operator<=(const PhysicalNumber&,const PhysicalNumber&);
		friend bool operator>=(const PhysicalNumber&,const PhysicalNumber&);
		friend bool operator>(const PhysicalNumber&,const PhysicalNumber&);

		// Increasing and decreasing by one operators
		// Postfix: (A--)
		PhysicalNumber operator++(int);
		PhysicalNumber operator--(int);
		// Prefix: (--A)
		PhysicalNumber operator++();
		PhysicalNumber operator--();

		// I/O
		friend std::ostream& operator<<(std::ostream&, const PhysicalNumber&);
		friend std::istream& operator>>(std::istream&, PhysicalNumber&);

		// Bonus:
		PhysicalNumber& operator/(const PhysicalNumber&);
		PhysicalNumber& operator* (const PhysicalNumber&);
		PhysicalNumber& operator*=(const PhysicalNumber&);
		PhysicalNumber& operator/=(const PhysicalNumber&);
		
		// Checking:
		bool verifier(const PhysicalNumber&, const PhysicalNumber&) const;
		bool is_len(const PhysicalNumber&, const PhysicalNumber&) const;
		bool is_mass(const PhysicalNumber&, const PhysicalNumber&) const;
		bool is_time(const PhysicalNumber&, const PhysicalNumber&) const;
	};
}
#endif
