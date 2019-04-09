/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <stdlib.h>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

  	PhysicalNumber km(1, Unit::KM);
		PhysicalNumber m(1, Unit::M);
		PhysicalNumber cm(1, Unit::CM);
		
		PhysicalNumber ton(1, Unit::TON);
		PhysicalNumber kg(1, Unit::KG);
		PhysicalNumber g(1, Unit::G);
		
		PhysicalNumber hour(1, Unit::HOUR);
		PhysicalNumber min(1, Unit::MIN);
    PhysicalNumber sec(1, Unit::SEC);
   
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    

    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    .setname("Cant add [+],[-],[+=],[-=]")

		.CHECK_THROWS(km + ton)  .CHECK_THROWS(km - ton) .CHECK_THROWS(km += ton)  .CHECK_THROWS(km -= ton) 
		.CHECK_THROWS(km + kg)   .CHECK_THROWS(km - kg) .CHECK_THROWS(km += kg)  .CHECK_THROWS(km -= kg)
		.CHECK_THROWS(km + g)  .CHECK_THROWS(km - g) .CHECK_THROWS(km += g) .CHECK_THROWS(km -= g)
		.CHECK_THROWS(km + hour) .CHECK_THROWS(km - hour) .CHECK_THROWS(km +=hour) .CHECK_THROWS(km -= hour)
		.CHECK_THROWS(km + min) .CHECK_THROWS(km - min) .CHECK_THROWS(km += min) .CHECK_THROWS(km -= min)
  	    .CHECK_THROWS(km + sec) .CHECK_THROWS(km - sec) .CHECK_THROWS(km += sec) .CHECK_THROWS(km -= sec)

			.CHECK_THROWS(m + ton) .CHECK_THROWS(m - ton) .CHECK_THROWS(m += ton).CHECK_THROWS(m -= ton)
			.CHECK_THROWS(m + kg) .CHECK_THROWS(m - kg) .CHECK_THROWS(m += kg) .CHECK_THROWS(m -= kg)
			.CHECK_THROWS(m + g) .CHECK_THROWS(m - g) .CHECK_THROWS(m += g) .CHECK_THROWS(m -= g)
			.CHECK_THROWS(m + hour) .CHECK_THROWS(m - hour) .CHECK_THROWS(m += hour) .CHECK_THROWS(m -= hour)
			.CHECK_THROWS(m + min) .CHECK_THROWS(m - min) .CHECK_THROWS(m += min) .CHECK_THROWS(m -= min)
			.CHECK_THROWS(m + sec) .CHECK_THROWS(m - sec) .CHECK_THROWS(m += sec) .CHECK_THROWS(m -= sec)

			.CHECK_THROWS(cm + ton) .CHECK_THROWS(cm - ton) .CHECK_THROWS(cm += ton) .CHECK_THROWS(cm + ton)
			.CHECK_THROWS(cm + kg) .CHECK_THROWS(cm - kg) .CHECK_THROWS(cm += kg) .CHECK_THROWS(cm -= kg)
			.CHECK_THROWS(cm + g) .CHECK_THROWS(cm - g) .CHECK_THROWS(cm += g) .CHECK_THROWS(cm -= g)
			.CHECK_THROWS(cm + hour) .CHECK_THROWS(cm - hour) .CHECK_THROWS(cm += hour) .CHECK_THROWS(cm -= hour)
			.CHECK_THROWS(cm + min) .CHECK_THROWS(cm - min) .CHECK_THROWS(cm += min) .CHECK_THROWS(cm -= min)
			.CHECK_THROWS(cm + sec) .CHECK_THROWS(cm - sec) .CHECK_THROWS(cm += sec) .CHECK_THROWS(cm -= sec)

			.CHECK_THROWS(hour + ton) .CHECK_THROWS(hour - ton) .CHECK_THROWS(hour += ton) .CHECK_THROWS(hour -= ton)
			.CHECK_THROWS(hour + kg) .CHECK_THROWS(hour - kg) .CHECK_THROWS(hour += kg) .CHECK_THROWS(hour -= kg)
			.CHECK_THROWS(hour + g) .CHECK_THROWS(hour - g) .CHECK_THROWS(hour += g) .CHECK_THROWS(hour -= g)
			
      .setname("Add [+],[-],[+=],[-=]")

			.CHECK_OK(cm + km) .CHECK_OK(cm - km) .CHECK_OK(cm += km) .CHECK_OK(cm -= km)
			.CHECK_OK(cm + m) .CHECK_OK(cm - m) .CHECK_OK(cm += m) .CHECK_OK(cm -= m)
			.CHECK_OK(m + km) .CHECK_OK(m - km) .CHECK_OK(m += km) .CHECK_OK(m -= km)

			.CHECK_OK(ton + kg) .CHECK_OK(ton - kg) .CHECK_OK(ton += kg) .CHECK_OK(ton -= kg)
			.CHECK_OK(ton + g) .CHECK_OK(ton - g) .CHECK_OK(ton += g) .CHECK_OK(ton -= g)
			.CHECK_OK(kg + g) .CHECK_OK(kg - g) .CHECK_OK(kg += g) .CHECK_OK(kg -= g)

			.CHECK_OK(hour + min) .CHECK_OK(hour - min) .CHECK_OK(hour += min) .CHECK_OK(hour -= min)
			.CHECK_OK(hour + sec) .CHECK_OK(hour - sec) .CHECK_OK(hour += sec) .CHECK_OK(hour -= sec)
			.CHECK_OK(min + sec) .CHECK_OK(min - sec) .CHECK_OK(min += sec += min -=min ) .CHECK_OK(min -= sec)
            .CHECK_OK(min++)

			.setname("Checkoutput [+],[-]")
			.CHECK_OUTPUT(cm + km,"100001[cm]") .CHECK_OUTPUT(cm - km,"-99999[cm]")
			.CHECK_OUTPUT(cm + m,"101[cm]") .CHECK_OUTPUT(cm - m,"-99[cm]")
			.CHECK_OUTPUT(m + km,"1001[m]") .CHECK_OUTPUT(m - km,"-999[m]") 


	  .CHECK_OUTPUT(ton + ton,"2[ton]") .CHECK_OUTPUT(ton - ton,"0[ton]") 
	  .CHECK_OUTPUT(ton + kg,"1.001[ton]") .CHECK_OUTPUT(ton - kg,"0.999[ton]") 
      .CHECK_OUTPUT(kg + g,"1.001[kg]") .CHECK_OUTPUT(kg - g,"0.999[kg]")

      .CHECK_OUTPUT(hour + hour,"2[hour]") .CHECK_OUTPUT(hour+min-min+min+min+min+min,"1.06668[hour]") 
	  .CHECK_OUTPUT(ton + kg,"1.001[ton]") .CHECK_OUTPUT(ton - kg,"0.999[ton]") 
      .CHECK_OUTPUT(kg + g,"1.001[kg]") .CHECK_OUTPUT(kg - g,"0.999[kg]")

      .setname("Checkoutput [+],[-] unary")
      .CHECK_OUTPUT(+m,"1[m]") .CHECK_OUTPUT(-m,"-1[m]") .CHECK_OUTPUT(m,"1[m]")
      .CHECK_OUTPUT(+kg,"1[kg]") .CHECK_OUTPUT(-kg,"-1[kg]") .CHECK_OUTPUT(kg,"1[kg]")  
      .CHECK_OUTPUT(+sec,"1[sec]") .CHECK_OUTPUT(-sec,"-1[sec]") .CHECK_OUTPUT(sec,"1[sec]")    
      
      .setname("Checkoutput [++],[--]")
      .CHECK_OUTPUT(++++m,"3[m]") .CHECK_OUTPUT(--++--m,"2[m]") .CHECK_OUTPUT(--m,"1[m]")
      .CHECK_OUTPUT(ton++,"1[ton]") .CHECK_OUTPUT(ton--,"2[ton]") 

      .setname("Checkoutput [<<],[>>]")
      .CHECK_OK(istringstream("24[hour]") >> a) .CHECK_OUTPUT(a,"24[hour]") 
      .CHECK_THROWS(istringstream("[cm]3") >> b) 
      .setname("...")
  
      .CHECK_OK(PhysicalNumber(2,Unit::HOUR) == PhysicalNumber(120,Unit::MIN))
      .print(cout, /*show_grade=*/false);
      
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
