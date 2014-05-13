#include <iostream>
#include "Circle.h"
#include "Point.h"

int main(int argc, char *argv[]){
	std::cout << "Testing.." << std::endl;
	
	Point p;
	Circle c;
	std::cin >> p;
	std::cout << " ----- " << std::endl;
	std::cout << p << std::endl;
	std::cin >> c;
	std::cout << " ----- " << std::endl;
	std::cout << c << std::endl;

	std::cout << "area: " <<  c.area() << std::endl;
	std::cout << "circumference: " << c.circumference() << std::endl;
	std::cout << "compare: " << c.compare(p) << std::endl;
	std::cout << "arclength: " << c.arclength(45) << std::endl;
	
return 0;
}
