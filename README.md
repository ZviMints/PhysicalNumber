<img src="https://media.licdn.com/dms/image/C4D0BAQGD7npMPoXymw/company-logo_200_200/0?e=2159024400&v=beta&t=TZ8Ub3U2jCZgA1_kAx6SE8jmAcSJkbiZAuN6Kn1_lW0" height="100px">

# PhysicalNumber :boom:
PhysicalNumber Project made during CPP course at Ariel University 2019. <br>
Made by: Zvi Mints and Or Abuhazira and Eilon Tsadok.

# What is PhysicalNumber:
PhysicalNumber class represent number of some specific unit.
for example 5kg or 3.2 ton.
This class contains units of:
<br>
<b>TIME</b> - SECOND, MINUTE, HOUR. <br>
<b>DISTANCE</b> - CM, METER, KM. <br>
<b>WEIGHT</b> - GRAM, KG, TON. <br>

## How to use:
Declare of a parameter from the class PhysicalNumber and then insert its value(double) and unit. <br>
For the unit parameter you could insert: { [sec], [min], [hour], [cm], [m], [km], [g], [kg], [ton] }. <br>
For examlpe: PhysicalNumber p(5.3,[km]); <br>

## The class function:
It let you compare between PhysicalNumber parameters. such as: >,>=,<,<=,==<!=. <br>
It let you to initialize PhysicalNumber parameter by other parameter from the same type. such as: PhysicalNumber q = p; <br>
It let you do mathematics function between PhysicalNumber parameters.  <br>
Such as: p++, p--, ++p, --p, p+q, p-q, p+=q, p-=q, -p, +p. <br>
Moreover it let you use PhysicalNumber with ostream and istream parameters. Such as std::cout<<p; or std::cin>>p;. <br>

