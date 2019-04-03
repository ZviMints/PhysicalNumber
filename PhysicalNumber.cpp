#include "PhysicalNumber.h"
#include "Calculator.h"
#include <math.h> 

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
            case Unit::MIN :
            switch(other._type)
            {
                case Unit::HOUR : 
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
            case Unit::MIN :
            switch(other._type)
            {
                case Unit::HOUR : 
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
                case Unit::HOUR : 
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
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) {
   PhysicalNumber ans = *this + other;
   this->_value = ans._value;
   return *this; 
 }
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other) {
   PhysicalNumber ans = *this - other;
   this->_value = ans._value;
   return *this;   
}
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other) { 
    this->_value = other._value;
    this->_type = other._type;
    return *this;
}

// 6 comparison operators                                                              
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
PhysicalNumber PhysicalNumber::operator++(int) {
PhysicalNumber temp(*this);
this->_value ++ ;
return temp;
}
PhysicalNumber PhysicalNumber::operator--(int) { 
PhysicalNumber temp(*this);
this->_value -- ;
return temp;
}
// Prefix: (--A)
PhysicalNumber& PhysicalNumber::operator++() {
    ++ this->_value;
    return *this;
}    
PhysicalNumber& PhysicalNumber::operator--() { 
    -- this->_value;
    return *this;
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
} // Need to add checks
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& other) {
std::string ans;
is >> ans;
double new_value = 0;
std::string s_type = "";
int n = ans.find('[') - 1;
for(int i=0; i<=n; i++)
{
    new_value += pow(10,n-i) * (ans[i] - '0');
}
for(int i=n+2; ans[i]!=']'; i++)
{
           s_type += ans[i]; 
}
Unit new_type;
if( s_type.compare("km") == 0 ) new_type = Unit::KM; 
else if( s_type.compare("m") == 0 ) new_type = Unit::M; 
else if( s_type.compare("cm") == 0 ) new_type = Unit::CM; 

else if( s_type.compare("ton") == 0 ) new_type = Unit::TON; 
else if( s_type.compare("kg") == 0 ) new_type = Unit::KG; 
else if( s_type.compare("g") == 0 ) new_type = Unit::G; 

else if( s_type.compare("hour") == 0 ) new_type = Unit::HOUR; 
else if( s_type.compare("min") == 0 ) new_type = Unit::MIN; 
else new_type = Unit::SEC; // ( s_type.compare("sec") ==0  )

other._type = new_type;
other._value = new_value;
return is;
}

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
