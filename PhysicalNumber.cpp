#include "PhysicalNumber.h"
#include "Calculator.h"
using namespace ariel;
PhysicalNumber::PhysicalNumber(double _value, Unit _type)
 : _value(_value), _type(_type) {}
// arithmetic operators
PhysicalNumber PhysicalNumber::operator-() { return PhysicalNumber(-_value,_type); }
PhysicalNumber PhysicalNumber::operator+() { return PhysicalNumber(_value,_type); }
PhysicalNumber& PhysicalNumber::operator+(const PhysicalNumber& other) { 
if(!verifier(*this,other)) throw std::string("Cant do [+] operation");
else
    {
    if(is_len(*this,other))
    {
        switch(this->_type)
        {
            case Unit::KM : 
            switch(other._type)
            {
                case Unit::KM : 
                this->_value += other._value;
                break;
                case Unit::M :
                this->_value += Calculator::M_TO_KM(other._value);
                break;
                case Unit::CM :
                this->_value += Calculator::CM_TO_KM(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::KM : 
                this->_value += Calculator::KM_TO_M(other._value);
                break;
                case Unit::M :
                this->_value += other._value;
                break;
                case Unit::CM :
                this->_value += Calculator::CM_TO_M(other._value);
                break;
            }            
            break;
            case Unit::CM :
            switch(other._type)
            {
                case Unit::KM : 
                this->_value += Calculator::KM_TO_CM(other._value);
                break;
                case Unit::M :
                this->_value += Calculator::M_TO_CM(other._value);  
                break;
                case Unit::CM :
                this->_value += other._value;   
                break;
            }
            break;
        }
    }
    else if(is_mass(*this,other))
    {
            // NEED TO IMPLEMENT
    }
    else // time family
    {
            // NEED TO IMPLEMENT
    }
    return *this;
    }
}
PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& other) { 
if(!verifier(*this,other)) throw std::string("Cant do [-] operation");
else
    {
    if(is_len(*this,other))
    {
        switch(this->_type)
        {
            case Unit::KM : 
            switch(other._type)
            {
                case Unit::KM : 
                this->_value -= other._value;
                break;
                case Unit::M :
                this->_value -= Calculator::M_TO_KM(other._value);
                break;
                case Unit::CM :
                this->_value -= Calculator::CM_TO_KM(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::KM : 
                this->_value -= Calculator::KM_TO_M(other._value);
                break;
                case Unit::M :
                this->_value -= other._value;
                break;
                case Unit::CM :
                this->_value -= Calculator::CM_TO_M(other._value);
                break;
            }            
            break;
            case Unit::CM :
            switch(other._type)
            {
                case Unit::KM : 
                this->_value -= Calculator::KM_TO_CM(other._value);
                break;
                case Unit::M :
                this->_value -= Calculator::M_TO_CM(other._value);  
                break;
                case Unit::CM :
                this->_value -= other._value;   
                break;
            }
            break;
        }
    }
    else if(is_mass(*this,other))
    {
            // NEED TO IMPLEMENT
    }
    else // time family
    {
            // NEED TO IMPLEMENT
    }
    return *this;
    }
}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other) { return *this; }

// 6 comparison operators
bool PhysicalNumber::operator==(PhysicalNumber& p1) { 
    if ((this->_type == p1._type ) && (this->_value == p1._value)) return true;
    return false;
}
bool PhysicalNumber::operator<(PhysicalNumber& p1) {
    if(this->_type == p1._type)
    {
        return (this->_value < p1._value);
    }
    else throw std::string("Cant compare");
}
bool PhysicalNumber::operator!=(PhysicalNumber& p1) { if (!(*this == p1)) return true; else return false; }
bool PhysicalNumber::operator>=(PhysicalNumber& p1) { if (!(*this < p1)) return true; else return false; }
bool PhysicalNumber::operator>(PhysicalNumber& p1) {  if ((p1 < *this)) return true; else return false; }
bool PhysicalNumber::operator<=(PhysicalNumber& p1) { if (!(*this > p1)) return true; else return false; }

// Increasing and decreasing by one operators
// Postfix: (A--)
PhysicalNumber PhysicalNumber::operator++(int) { return *this; }
PhysicalNumber PhysicalNumber::operator++() { return *this; }
// Prefix: (--A)
PhysicalNumber PhysicalNumber::operator--(int) { return *this; }
PhysicalNumber PhysicalNumber::operator--() { return *this; }

// I/O
std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber& other) {
std::string typeof;
switch(other._type) 
{
    case Unit::KM : typeof = "km"; break;
    case Unit::M : typeof = "m"; break;
    case Unit::CM : typeof = "cm"; break;
    case Unit::TON : typeof = "ton"; break;
    case Unit::KG : typeof = "kg"; break;
    case Unit::G : typeof = "g"; break;
    case Unit::HOUR : typeof = "hour"; break;
    case Unit::MIN : typeof = "min"; break;
    case Unit::SEC : typeof = "sec"; break;
}
return os << other._value << "[" << typeof <<"]";
}
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& other) { return is; }

// Bonus:
PhysicalNumber& PhysicalNumber::operator/(const PhysicalNumber& other) { return *this;  }
PhysicalNumber& PhysicalNumber::operator* (const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator*=(const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator/=(const PhysicalNumber& other) { return *this; }

// Checking:
bool PhysicalNumber::verifier(const PhysicalNumber& input1, const PhysicalNumber& input2) const {
if( (is_len(input1,input2) || is_mass(input1,input2) || is_time(input1,input2)) ) return true;
else return false;
}
bool PhysicalNumber::is_len(const PhysicalNumber& input1, const PhysicalNumber& input2) const {
Unit type1 = input1._type;
Unit type2 = input2._type;
if(      ((type1 == Unit::KM) || (type1 == Unit::M) || (type1 == Unit::CM)) && 
         ((type2 == Unit::KM) || (type2 == Unit::M) || (type2 == Unit::CM))         ) return true;
else return false;
}
bool PhysicalNumber::is_mass(const PhysicalNumber& input1, const PhysicalNumber& input2) const {
Unit type1 = input1._type;
Unit type2 = input2._type;   
 if(      ((type1 == Unit::TON) || (type1 == Unit::KG) || (type1 == Unit::G)) && 
         ((type2 == Unit::TON) || (type2 == Unit::KG) || (type2 == Unit::G))         ) return true;
else return false;   
 }
bool PhysicalNumber::is_time(const PhysicalNumber& input1, const PhysicalNumber& input2) const {
Unit type1 = input1._type;
Unit type2 = input2._type;
if(      ((type1 == Unit::HOUR) || (type1 == Unit::MIN) || (type1 == Unit::SEC)) && 
         ((type2 == Unit::HOUR) || (type2 == Unit::MIN) || (type2 == Unit::SEC))         ) return true;
else return false;    
}
