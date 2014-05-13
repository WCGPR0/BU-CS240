#include "Circle.h"

#define PI 3.14159265358979

#define C_DEBUG false

using namespace std;

//TODO
//Default Constructor (Assigns unit circle)
Circle::Circle(){
	if(C_DEBUG) {cout << "-- Circle -- Default constructor called." << endl;}
	center = Point();
	radius = 1;
}

//Copy Constructor (Copies values from the argument)
Circle::Circle(const Circle &other){
	if(C_DEBUG) {cout << "-- Circle -- Copy constructor called." << endl;}
	center = other.center;
	radius = other.radius;
}

//TODO
//Explicit Value Constructor (Uses parameters to assign to circle)
Circle::Circle(Point center, double radius) {
	if(C_DEBUG) {cout << "-- Circle -- Explicit value constructor called." << endl;	}
this->center = center;
this->radius = abs(radius);
}

//Assignment Operator (copies values from the argument)
Circle& Circle::operator=(const Circle &rhs){
	if(C_DEBUG) {cout << "-- Circle -- Assignment operator called." << endl;}
	//Alias test
	if(this!=&rhs){
		center = rhs.center;
		radius = rhs.radius;
	}
	return *this;
}

//TODO
//Returns the area of the circle
double Circle::area(){
	return PI * pow(radius, 2);
}

//TODO
//Returns the circumference of the circle
double Circle::circumference(){
	return PI * 2 * radius;
}

//TODO
//Determines whether or not a point is inside (positive), on (zero), or outside (negative) the edge of the circle
int Circle::compare(Point &point){
	return (radius - (point-center));
}

//TODO
//Returns the length of the arc that subtends the central angle (central angle measurement in degrees)
double Circle::arclength(double central_angle){
	while (central_angle < 0) central_angle+=360;
	if (central_angle > 360) central_angle = fmod(central_angle,360);
	return circumference()* central_angle/360;
}

//Destructor
Circle::~Circle(){
	if(C_DEBUG) {cout << "-- Circle -- Destructor called." << endl;}
}

//TODO
//Prompts the user for a Point (center) and stores it
//then prompts the user for the radius and stores it
istream& operator>>(istream& is, Circle& c){
	if(C_DEBUG) {cout << "-- Operator >> called on a Circle." << endl;}
	cout << "Input Center Coordinates: ";	
	is >> c.center;
	cout << "Input Radius: ";
	is >> c.radius;
	c.radius = abs(c.radius);
	return is;
}

//TODO
//Prints out (on one line, and separated with spaces) the center and radius of the circle (labeled and separated with a colon and space)
ostream& operator<<(ostream& os, Circle& c){
	if(C_DEBUG) {cout << "-- Operator << called on a Circle." << endl;}
	os << "Center:	" << c.center << ";" << endl << "Radius:	" << c.radius;
	return os;
}

//Checks if two Circles is equivalent
bool Circle::operator==(const Circle& c){
	return this->center == c.center && this->radius == c.radius;
}
