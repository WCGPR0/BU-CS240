#include <iostream>
#include "Point.h"
#include "Circle.h"

#define PI 3.14159265358979

using namespace std;

int main(){
	//POINT
	cout << "POINT TESTS:" << endl;

	//Default Constructor
	Point p1;
	
	//Copy Constructor
	Point p2(p1);

	//Explicit Value Constructor
	Point p3(0,1);
	Point p4(-1,0);
	Point p5(3,4);

	//Assignment Operator
	p2 = p5;

	//- Operator

	double distance = p3 - p4;
	if(distance != sqrt(2.0)){ 
		cout << "Failed operator -" << endl; 
		cout << "  Expected " << sqrt(2.0) << " computed " << distance << endl;
				}
	distance = p4 - p3;
	if(distance != sqrt(2.0)){ 
		cout << "Failed operator -" << endl; 
		cout << "  Expected " << sqrt(2.0) << " computed " << distance << endl;
	}
	distance = p1 - p5;
	if(distance != 5.0) { 
		cout << "Failed operator -" << endl; 
		cout << "  Expected " << 5.0 << " computed " << distance << endl;
	}

	//Destructor
	Point *heap_point = new Point(5,6);
	//call the destructor, run with valgrind
	delete heap_point;

	//>> and << Operators
	Point p6, p7, p8, p9;
	cout << endl << "Input the following point: (-1,2)" << endl;
	cin >> p6;
	cout << "(-1,2) -- " << p6 << endl;
	cout << endl << "Input the following point: (10,-15)" << endl;
	cin >> p7;
	cout << "(10,-15) -- " << p7 << endl;
	cout << endl << "Input the following point: (100,1500)" << endl;
	cin >> p8;
	cout << "(100,1500) -- " << p8 << endl;
	cout << endl << "Input the following point: (-20435,-1452)" << endl;
	cin >> p9;
	cout << "(-20435,-1452) -- " << p9 << endl;


	
	//CIRCLE
	cout << "CIRCLE TESTS:" << endl;

	//Default Constructor
	Circle c1;

	//Copy Constructor
	Circle c2(c1);

	//Explicit Value Constructor
	Circle c3(p1,5);
	Circle c4(p2,2.236);
	Circle c5(p3,0);
	Circle c6(p4,-10);

	//Assignment Operator
	Circle c7;
	c7 = c6;
	
	//Area
	double area = c3.area();
	if(area != PI*25) { 
		cout << "Failed area " << c3 << endl;
		cout << "  Expected " << PI*25 << " computed " << area << endl;
	}
	area = c4.area();
	if(area != PI*2.236*2.236) { 
		cout << "Failed area " << c4 << endl;
		cout << "  Expected " << PI*2.236*2.236 << " computed " << area << endl;
	}
	area = c5.area();
	if(area != 0) { 
		cout << "Failed area " << c5 << endl;
		cout << "  Expected " << 0.0 << " computed " << area << endl;
	}
	area = c6.area();
	if(area != PI*100) { 
		cout << "Failed area " << c6 << endl;
		cout << "  Expected " << PI*100 << " computed " << area << endl;
	}


	//Circumference
	double circumference = c1.circumference();
	if(circumference != 2*PI) { 
		cout << "Failed circumference " << c1 << endl;
		cout << "  Expected " << 2*PI << " computed " << circumference << endl;
	}
	circumference = c3.circumference();
	if(circumference != PI*10) { 
		cout << "Failed circumference " << c3 << endl;
		cout << "  Expected " << PI*10 << " computed " << circumference << endl;
	}
	circumference = c4.circumference();
	if(circumference != PI*4.472) { 
		cout << "Failed circumference " << c4 << endl;
		cout << "  Expected " << PI*4.472 << " computed " << circumference << endl;
	}
	circumference = c5.circumference();
	if(circumference != 0) { 
		cout << "Failed circumference " << c5 << endl;
		cout << "  Expected " << 0.0 << " computed " << circumference << endl;
	}
	circumference = c6.circumference();
	if(circumference != PI*2*10) { 
		cout << "Failed circumference " << " " << c6 << endl;
		cout << "  Expected " << PI*2*10 << " computed " << circumference << endl;
	}
	

	//Compare
	Point mp(3,4);
	c7 = Circle();
	if(c7.compare(mp) >= 0) { cout << "Failed compare test for outside circle." << endl;}
	mp = Point();
	if(c7.compare(mp) <= 0) { cout << "Failed compare test for inside circle." << endl;}
	mp = Point(1,0);
	if(c7.compare(mp) != 0) { cout << "Failed compare test for on circle." << endl;}
	
	//Arclength
	double al = c7.arclength(0);
	if(al != 0) { 
		cout << "Failed arclength test with 0 degrees." << endl;
		cout << "  Expected " << 0 << " computed " << al << endl;
	}
	al = c7.arclength(90);
	if(al != PI/2.0) { 
		cout << "Failed arclength test with 90 degrees." << endl;
		cout << "  Expected " << PI/2.0 << " computed " << al << endl;
	}
	al = c7.arclength(-90);
	if(al != 3*PI/2.0) { 
		cout << "Failed arclength test with -90 degrees." << endl;
		cout << "  Expected " << 3*PI/2.0 << " computed " << al << endl;
	}
	al = c7.arclength(540);
	if(al != PI) { 
		cout << "Failed arclength test with 540 degrees." << endl;
		cout << "  Expected " << PI << " computed " << al << endl;
	}
	
	//Destructor
	Circle* circle_heap = new Circle();
	delete circle_heap;

	//>> and << Operators
	cout << endl << "Enter circle with center (2,3) and radius 10" << endl;
	Circle c8;
	cin >> c8;
	cout << "Center: (2,3); Radius: 10 " << " -- " << c8 << endl;

	cout << endl << "Enter circle with center (1,0) and radius -10" << endl;
	cin >> c8;
	cout << "Center: (1,0); Radius: 10 " << " -- " << c8 << endl;

	cout << endl << "Enter circle with center (-1,2) and radius 3.5" << endl;
	cin >> c8;
	cout << "Center: (-1,2); Radius 3.5 " << " -- " << c8 << endl;

	cout << endl << "Enter circle with center (-2,-4) and radius -2.7" << endl;
	cin >> c8;
	cout << "Center: (-2,-4); Radius 2.7 " << " -- " << c8 << endl;


	/**
		Write test cases for your == operator here.
		To ease testing, you can comment out the rest of the
		code in the main function for this purpose. However,
		be sure that when you submit it, you reverse the
		commenting of the provided code.
	**/  


	return 0;
}
