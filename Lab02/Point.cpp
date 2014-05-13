#include "Point.h"

#define P_DEBUG true

using namespace std;

//TODO
//Default Constructor (Assigns origin)
Point::Point(){
	if(P_DEBUG) {cout << "-- Point -- Default constructor called." << endl;}
	x = 0;
	y = 0;	
}

//Copy Constructor (Copies values from the argument)
Point::Point(const Point& point){
	if(P_DEBUG) {cout << "-- Point -- Copy constructor called." << endl;}
	x = point.x;
	y = point.y;
}

//TODO
//Explicit Value Constructor (Uses parameters to assign to point)
Point::Point(int x, int y) : x(x), y(y){
	if(P_DEBUG) {cout << "-- Point -- Explicit value constructor called." << endl;}
}

//Assignment Operator (copies values from the argument)
Point& Point::operator=(const Point &rhs){
	if(P_DEBUG) {cout << "-- Point -- Assignment operator called." << endl;}
	//Alias test
	if(this!=&rhs){
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

//TODO
//Computes the difference (Euclidean Distance) of two points
double Point::operator-(const Point &p) const{
	if(P_DEBUG) {cout << "-- Point -- Operator - called." << endl;}
	return sqrt(pow(p.x-x,2)+pow(p.y-y,2));
}

//Destructor
Point::~Point(){
	if(P_DEBUG) {cout << "-- Point -- Destructor Called." << endl;}
}

//TODO
//Prints out (on one line in (x,y) format) the value of the point
ostream& operator<<(ostream& os, const Point& p){
	if(P_DEBUG) {cout << "-- Operator << called on a Point" << endl;}
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}

//TODO
//Prompts the user for an x coordinate and stores it
//then prompts the user for a y coordinate and stores it
istream& operator>>(istream& is, Point& p){
	if(P_DEBUG) {cout << "-- Operator >> called on a Point" << endl;}
	cout << "Input X: ";
	is >> p.x;
	cout << "Input Y: "; 
	is >> p.y;
	return is;
}

//Checks if two points are equal
bool Point::operator==(const Point& p)
{
return ((this->x == p.x) && (this->y == p.y));
}
