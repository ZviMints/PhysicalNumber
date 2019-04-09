#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
#include <iostream>
namespace ariel {
	class PhysicalNumber {

		double _value;
		Unit _type;

	public:
		// Constructors:
		PhysicalNumber(double, Unit);

		// arithmetic operators
		const PhysicalNumber operator-() const; //[V]
		const PhysicalNumber operator+() const; //[V]
		const PhysicalNumber operator+(const PhysicalNumber&) const; //[V]
		const PhysicalNumber operator-(const PhysicalNumber&) const; //[V]
		PhysicalNumber& operator+=(const PhysicalNumber&);  //[V]
		PhysicalNumber& operator-=(const PhysicalNumber&); //[V]
		PhysicalNumber& operator=(const PhysicalNumber&); //[V]

		// 6 comparison operators
		friend bool operator==(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
		friend bool operator<(const PhysicalNumber&, const PhysicalNumber&) const;  //[V]
		friend bool operator!=(const PhysicalNumber&, const PhysicalNumber&) const; //[V]
		friend bool operator<=(const PhysicalNumber&,const PhysicalNumber&) const; //[V]
		friend bool operator>=(const PhysicalNumber&,const PhysicalNumber&) const; //[V]
		friend bool operator>(const PhysicalNumber&,const PhysicalNumber&) const; //[V]

		// Increasing and decreasing by one operators
		// Postfix: (A--)
		const PhysicalNumber operator++(int); //[V]
		const PhysicalNumber operator--(int); //[V]
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
		static bool verifier(const PhysicalNumber&, const PhysicalNumber&); //[V]
		static bool is_len(const PhysicalNumber&, const PhysicalNumber&); //[V]
		static bool is_mass(const PhysicalNumber&, const PhysicalNumber&); //[V]
		static bool is_time(const PhysicalNumber&, const PhysicalNumber&); //[V]
	};
}
#endif
