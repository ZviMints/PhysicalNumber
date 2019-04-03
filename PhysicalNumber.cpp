#include "PhysicalNumber.h"
#include "Calculator.h"
using namespace ariel;
PhysicalNumber::PhysicalNumber(double _value, Unit _type)
 : _value(_value), _type(_type) {}
// arithmetic operators
PhysicalNumber PhysicalNumber::operator-() { return PhysicalNumber(-_value,_type); }
PhysicalNumber PhysicalNumber::operator+() { return PhysicalNumber(_value,_type); }
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) { 
if(!verifier(*this,other)) throw std::string("Cant do [+] operation");
else
    {
    double new_value = this->_value;
    Unit new_type = this->_type;
    if(is_len(*this,other)) // Its in [KM,M,M]
    {
        switch(this->_type) // Its in [KM,M,M]
        {
            case Unit::KM : 
            switch(other._type)
            {
                case Unit::KM : 
                new_value += other._value;
                break;
                case Unit::M :
                new_value += Calculator::M_TO_KM(other._value);
                break;
                default:
                new_value += Calculator::CM_TO_KM(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::KM : 
                new_value += Calculator::KM_TO_M(other._value);
                break;
                case Unit::M :
                new_value += other._value;
                break;
                default:
                new_value += Calculator::CM_TO_M(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::KM : 
                new_value += Calculator::KM_TO_CM(other._value);
                break;
                case Unit::M :
                new_value += Calculator::M_TO_CM(other._value);  
                break;
                default:
                new_value += other._value;   
                break;
            }
            break;
        }
    }
    else if(is_mass(*this,other)) // Its in [TON,KG,G]
    {
        switch(this->_type) // Its in [TON,KG,G]
        {
            case Unit::TON : 
            switch(other._type)
            {
                case Unit::TON : 
                new_value += other._value;
                break;
                case Unit::KG :
                new_value += Calculator::KG_TO_TON(other._value);
                break;
                default:
                new_value += Calculator::G_TO_TON(other._value);
                break;
            }
            break;
            case Unit::KG :
            switch(other._type)
            {
                case Unit::TON : 
                new_value += Calculator::TON_TO_M(other._value);
                break;
                case Unit::KG :
                new_value += other._value;
                break;
                default:
                new_value += Calculator::G_TO_KG(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::TON : 
                new_value += Calculator::TON_TO_G(other._value);
                break;
                case Unit::KG :
                new_value += Calculator::KM_TO_CM(other._value);  
                break;
                default:
                new_value += other._value;   
                break;
            }
            break;
        }
    }
    else // Its in [HOUR,MIN,SEC]
    {
        switch(this->_type) // Its in [HOUR,MIN,SEC]
        {
            case Unit::HOUR : 
            switch(other._type)
            {
                case Unit::HOUR : 
                new_value += other._value;
                break;
                case Unit::MIN :
                new_value += Calculator::MIN_TO_HOUR(other._value);
                break;
                default:
                new_value += Calculator::SEC_TO_HOUR(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::TON : 
                new_value += Calculator::HOUR_TO_MIN(other._value);
                break;
                case Unit::MIN :
                new_value += other._value;
                break;
                default:
                new_value += Calculator::SEC_TO_MIN(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::TON : 
                new_value += Calculator::HOUR_TO_SEC(other._value);
                break;
                case Unit::MIN :
                new_value += Calculator::MIN_TO_SEC(other._value);  
                break;
                default:
                new_value += other._value;   
                break;
            }
            break;
        }
    }
    return PhysicalNumber(new_value,new_type);
    }
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) { 
if(!verifier(*this,other)) throw std::string("Cant do [-] operation");
else
    {
    double new_value = this->_value;
    Unit new_type = this->_type;
    if(is_len(*this,other)) // Its in [KM,M,M]
    {
        switch(this->_type) // Its in [KM,M,M]
        {
            case Unit::KM : 
            switch(other._type)
            {
                case Unit::KM : 
                new_value -= other._value;
                break;
                case Unit::M :
                new_value -= Calculator::M_TO_KM(other._value);
                break;
                default:
                new_value -= Calculator::CM_TO_KM(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::KM : 
                new_value -= Calculator::KM_TO_M(other._value);
                break;
                case Unit::M :
                new_value -= other._value;
                break;
                default:
                new_value -= Calculator::CM_TO_M(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::KM : 
                new_value -= Calculator::KM_TO_CM(other._value);
                break;
                case Unit::M :
                new_value -= Calculator::M_TO_CM(other._value);  
                break;
                default:
                new_value -= other._value;   
                break;
            }
            break;
        }
    }
    else if(is_mass(*this,other)) // Its in [TON,KG,G]
    {
        switch(this->_type) // Its in [TON,KG,G]
        {
            case Unit::TON : 
            switch(other._type)
            {
                case Unit::TON : 
                new_value -= other._value;
                break;
                case Unit::KG :
                new_value -= Calculator::KG_TO_TON(other._value);
                break;
                default:
                new_value -= Calculator::G_TO_TON(other._value);
                break;
            }
            break;
            case Unit::KG :
            switch(other._type)
            {
                case Unit::TON : 
                new_value -= Calculator::TON_TO_M(other._value);
                break;
                case Unit::KG :
                new_value -= other._value;
                break;
                default:
                new_value -= Calculator::G_TO_KG(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::TON : 
                new_value -= Calculator::TON_TO_G(other._value);
                break;
                case Unit::KG :
                new_value -= Calculator::KM_TO_CM(other._value);  
                break;
                default:
                new_value -= other._value;   
                break;
            }
            break;
        }
    }
    else // Its in [HOUR,MIN,SEC]
    {
        switch(this->_type) // Its in [HOUR,MIN,SEC]
        {
            case Unit::HOUR : 
            switch(other._type)
            {
                case Unit::HOUR : 
                new_value -= other._value;
                break;
                case Unit::MIN :
                new_value -= Calculator::MIN_TO_HOUR(other._value);
                break;
                default:
                new_value -= Calculator::SEC_TO_HOUR(other._value);
                break;
            }
            break;
            case Unit::M :
            switch(other._type)
            {
                case Unit::TON : 
                new_value -= Calculator::HOUR_TO_MIN(other._value);
                break;
                case Unit::MIN :
                new_value -= other._value;
                break;
                default:
                new_value -= Calculator::SEC_TO_MIN(other._value);
                break;
            }            
            break;
            default:
            switch(other._type)
            {
                case Unit::TON : 
                new_value -= Calculator::HOUR_TO_SEC(other._value);
                break;
                case Unit::MIN :
                new_value -= Calculator::MIN_TO_SEC(other._value);  
                break;
                default:
                new_value += other._value;   
                break;
            }
            break;
        }
    }
    return PhysicalNumber(new_value,new_type);
    }
}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other) { return *this; }
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other) { return *this; }

// 6 comparison operators                                                              //[V]
bool ariel::operator==(const PhysicalNumber& p1, const PhysicalNumber& p2) { 
    if ((p2._type == p1._type ) && (p2._value == p1._value)) return true;
    return false;
}
bool ariel::operator<(const PhysicalNumber& p1, const PhysicalNumber& p2) {
    if(p2._type == p1._type)
    {
        return (p2._value < p1._value);
    }
    else throw std::string("Cant compare");
}
bool ariel::operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 == p1)) return true; else return false; }
bool ariel::operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 < p1)) return true; else return false; }
bool ariel::operator>(const PhysicalNumber& p1, const PhysicalNumber& p2) {  if ((p1 < p2)) return true; else return false; }
bool ariel::operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2) { if (!(p2 > p1)) return true; else return false; }

// Increasing and decreasing by one operators
// Postfix: (A--)
PhysicalNumber PhysicalNumber::operator++(int) { return *this; }
PhysicalNumber PhysicalNumber::operator++() {
    double new_value = this->_value + 1;
    return PhysicalNumber(new_value, this->_type);
}    
// Prefix: (--A)
PhysicalNumber PhysicalNumber::operator--(int) { return *this; }
PhysicalNumber PhysicalNumber::operator--() { 
    double new_value = this->_value - 1;
    return PhysicalNumber(new_value, this->_type);
}

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

// Checking:                                                              //[V]
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
