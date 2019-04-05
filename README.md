# PhysicalNumber
PhysicalNumber Project made during CPP course at Ariel University 2019.

Project site: https://github.com/ZviMints/Binary-Search-Tree.git
Made by: Zvi Mints and Or Abuhazira and Eilon Tsadok.

# what is PhysicalNumber:
PhysicalNumber class represent number of some specific unit.
for example 5kg or 3.2 ton.
This class contains units of:
time - seconds, minute,hour.
Distance - cm,meter, km.
Weight - gram,kg,ton.

## How to use:
Declare of a parameter from the class PhysicalNumber and then insert its value(double) and unit.
For the unit parameter you could insert: [sec], [min], [hour], [cm], [m], [km], [g], [kg], [ton].
For examlpe:  PhysicalNumber p(5.3,[km]);

## The class function:
It let you compare between PhysicalNumber parameters. such as: >,>=,<,<=,==<!=.
It let you to initialize PhysicalNumber parameter by other parameter from the same type. such as: PhysicalNumber q = p;
It let you do mathematics function between PhysicalNumber parameters. 
Such as: p++, p--, ++p, --p, p+q, p-q, p+=q, p-=q, -p, +p.
Moreover it let you use PhysicalNumber with ostream and istream parameters. Such as std::cout<<p; or std::cin>>p;.
