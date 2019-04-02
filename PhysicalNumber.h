#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
#include <iostream>
namespace ariel {
	class PhysicalNumber {
		double _value;
		Unit _type;

	public:
		// Constructors :
		PhysicalNumber(double _value, Unit _type);
		const PhysicalNumber operator-() const;
		const PhysicalNumber operator+() const;
		const PhysicalNumber& operator+ (const PhysicalNumber& other) const;
		const PhysicalNumber& operator- (const PhysicalNumber& other) const;
		PhysicalNumber& operator+=(const PhysicalNumber& other);
		PhysicalNumber& operator-=(const PhysicalNumber& other);
		PhysicalNumber& operator=(const PhysicalNumber& other);

		// 6 comparison operators
		friend bool operator==(const PhysicalNumber& p1, const PhysicalNumber& p2); // Implement at .cpp file
		friend bool operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2) { return !(p1 == p2); }
		friend bool operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2) { return !(p1 > p2); }
		friend bool operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2) { return !(p1 < p2); }
		friend bool operator<(const PhysicalNumber& p1, const PhysicalNumber& p2); // Implement at .cpp file
		friend bool operator>(const PhysicalNumber& p1, const PhysicalNumber& p2) { return (p2 < p1); }

		// Increasing and decreasing by one operators
		// Postfix: (A--)
		PhysicalNumber& operator++(int);
		PhysicalNumber& operator++();
		// Prefix: (--A)
		PhysicalNumber& operator--(int);
		PhysicalNumber& operator--();

		// I/O
		friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& other);
		friend std::istream& operator>>(std::istream& is, PhysicalNumber& other);

		// Bonus:
		PhysicalNumber& operator/(const PhysicalNumber& other);
		PhysicalNumber& operator* (const PhysicalNumber& other);
		PhysicalNumber& operator*=(const PhysicalNumber& other);
		PhysicalNumber& operator/=(const PhysicalNumber& other);
		
		// Checking:
		bool verifier(const PhysicalNumber& input1, const PhysicalNumber& input2) const;
		bool is_len(const PhysicalNumber& input1, const PhysicalNumber& input2) const;
		bool is_mass(const PhysicalNumber& input1, const PhysicalNumber& input2) const;
		bool is_time(const PhysicalNumber& input1, const PhysicalNumber& input2) const;
	};
}
#endif
