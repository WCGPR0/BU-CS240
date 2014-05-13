#include <iostream>
#include "ClassB.h"

int main(){
	//Make a class 1 object, call methods on this object...
	ClassB test;

	//Can declare an int array like this.
	//int arr[] = {2,3,4,5,6};
	//or like this
	//int arr[2] = {1,2};
	std::cout << "TESTING: " << 2%4 << " | " << 4%2;

	std::cout << std::endl << "Testing Q1" << std::endl;
	int array[] = {1,2,3,2,1};
	std::cout << "The output of [1,2,3,2,1] 5 2 6 is: " << std::endl; 
	test.q1(array,5,2,6);
	
	std::cout << std::endl << "Testing Q2" << std::endl;
	test.q2(0,100);

	std::cout << std::endl << "Testing Q3" << std::endl;
	std::cout << test.q3(2,4) << std::endl;

	std::cout << std::endl << "Testing Q4" << std::endl;
	test.q4(true, false);

	std::cout << std::endl << "Testing Q5" << std::endl;
	test.q5();	

	return 0;
}
