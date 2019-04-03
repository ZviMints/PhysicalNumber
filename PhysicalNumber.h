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
		const PhysicalNumber operator-(); //[V]
		const PhysicalNumber operator+(); //[V]
		PhysicalNumber operator+(const PhysicalNumber&); //[V]
		PhysicalNumber operator-(const PhysicalNumber&); //[V]
		PhysicalNumber& operator+=(const PhysicalNumber&);  //[V]
		PhysicalNumber& operator-=(const PhysicalNumber&); //[V]
		PhysicalNumber& operator=(const PhysicalNumber&); //[V]

		// 6 comparison operators
		friend bool operator==(const PhysicalNumber&, const PhysicalNumber&); //[V]
		friend bool operator<(const PhysicalNumber&, const PhysicalNumber&);  //[V]
		friend bool operator!=(const PhysicalNumber&, const PhysicalNumber&); //[V]
		friend bool operator<=(const PhysicalNumber&,const PhysicalNumber&); //[V]
		friend bool operator>=(const PhysicalNumber&,const PhysicalNumber&); //[V]
		friend bool operator>(const PhysicalNumber&,const PhysicalNumber&); //[V]

		// Increasing and decreasing by one operators
		// Postfix: (A--)
		PhysicalNumber operator++(int); //[V]
		PhysicalNumber operator--(int); //[V]
		// Prefix: (--A)
		PhysicalNumber& operator++(); //[V]
		PhysicalNumber& operator--(); //[V]

		// I/O
		friend std::ostream& operator<<(std::ostream&, const PhysicalNumber&); //[V]
		friend std::istream& operator>>(std::istream&, PhysicalNumber&); //[V]

		// Bonus:
		PhysicalNumber& operator/(const PhysicalNumber&);
		PhysicalNumber& operator* (const PhysicalNumber&);
		PhysicalNumber& operator*=(const PhysicalNumber&);
		PhysicalNumber& operator/=(const PhysicalNumber&); 
		
		// Checking:
		bool verifier(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
		bool is_len(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
		bool is_mass(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
		bool is_time(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
	};
}
#endif
