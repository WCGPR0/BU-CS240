#include "ClassB.h"
#include <cstdlib>

int main(int argc, char *argv[]){
	if(argc < 2){
		std::cout << "Please provide an argument. This ";
		std::cout << "argument should be a number that ";
		std::cout << "corresponds to which question you ";
		std::cout << "would like to test." << std::endl;
		return -1;
	}


	ClassB test;

	if(atoi(argv[1]) == 0){
		/** 
		 	sizeof operator only return the byte size of the object, but when used with dynamic arrays, only the first element is determined because it's being passed either as a pointer or dereference. As of such, it's not very accurate in cases like this.
		 **/
		 
		std::cout << "sizeof(int) == " << sizeof(int) << std::endl;
		std::cout << "sizeof(bool) == " << sizeof(bool) << std::endl;
		std::cout << "sizeof(char) == " << sizeof(char) << std::endl;

		std::cout << "sizeof(int *) == " << sizeof(int *) << std::endl;
		std::cout << "sizeof(bool *) == " << sizeof(bool *) << std::endl;
		std::cout << "sizeof(char *) == " << sizeof(char *) << std::endl;
	
		std::cout << "sizeof(int[6]) == " << sizeof(int[6]) << std::endl;
		std::cout << "sizeof(bool[6]) == " << sizeof(bool[6]) << std::endl;
		std::cout << "sizeof(char[6]) == " << sizeof(char[6]) << std::endl;
		
		int* x = new int[6];
		bool* y = new bool[6];
		char* z = new char[6];

		std::cout << "sizeof(new int[6]) == " << sizeof(x) << " --> POINTER" << std::endl;
		std::cout << "sizeof(new bool[6]) == " << sizeof(y) << " --> POINTER" << std::endl;
		std::cout << "sizeof(new char[6]) == " << sizeof(z) << " --> POINTER" << std::endl;

		std::cout << "sizeof(&x) == " << sizeof(&x) << " --> DEREFRENCE" << std::endl;
		std::cout << "sizeof(&y) == " << sizeof(&y) << " --> DEREFRENCE" << std::endl;
		std::cout << "sizeof(&z) == " << sizeof(&z) << " --> DEREFRENCE" << std::endl;
		delete[] x;
		delete[] y;
		delete[] z;
		
		std::cout << "sizeof(x) == " << sizeof(x) << std::endl; 
		std::cout << "sizeof(y) == " << sizeof(y) << std::endl;
		std::cout << "sizeof(z) == " << sizeof(z) << std::endl;		
	
	} else if(atoi(argv[1]) == 1){
		std::cout << std::endl << "Testing Q1" << std::endl;
		int arr[] = {0,1,1,2,3,5,8};
		
		test.q1(arr, 7, 1, 4);
		std::cout << std::endl;

		test.q1(arr, 2, 1, 0);
		std::cout << std::endl;

		test.q1(arr, 0, 1, 10);
		std::cout << std::endl;

		test.q1(arr, -1, 10, 0);
		std::cout << std::endl;

		test.q1(NULL, 4, 1, 2);
		std::cout << std::endl;
	} else if(atoi(argv[1]) == 2){
		std::cout << std::endl << "Testing Q2" << std::endl;
		std::cout << std::endl;
		
		//odd, odd
		test.q2(1, 9);
		std::cout << std::endl;

		//odd, even
		test.q2(1, 10);
		std::cout << std::endl;
		
		//even, odd
		test.q2(0, 9);		
		std::cout << std::endl;
		
		//even, even
		test.q2(0, 8);
		std::cout << std::endl;
		
		//nothing printed
		test.q2(2, 2);
		std::cout << std::endl;
		
		//higher, lower
		test.q2(10, 2);
		std::cout << std::endl;
		
		//some negative numbers
		test.q2(-100, -80);
		std::cout << std::endl;
	} else if(atoi(argv[1]) == 3){
		//LCM of two integers
		int lcm = test.q3(5,15);
		if(lcm != 15){
			std::cout << "Failed: 5, 15" << std::endl;
			return -3;
		}
		lcm = test.q3(15,5);
		if(lcm != 15){
			std::cout << "Failed: 15, 5" << std::endl;
			return -3;
		}
		lcm = test.q3(6,4);
		if(lcm != 12){
			std::cout << "Failed: 6, 4" << std::endl;
			return -3;
		}
		lcm = test.q3(3,3);
		if(lcm != 3){
			std::cout << "Failed: 3, 3" << std::endl;		
			return -3;
		}
		lcm = test.q3(0,3);
		if(lcm != -1){
			std::cout << "Failed: 0, 3" << std::endl;
			return -3;
		}
		lcm = test.q3(4,-1);
		if(lcm != -1){
			std::cout << "Failed: 4, -1" << std::endl;
			return -3;
		}
		lcm = test.q3(-1,0);
		if(lcm != -1){
			std::cout << "Failed: -1, 0" << std::endl;
			return -3;
		}
		lcm = test.q3(-4,-6);
		if(lcm != -1){
			std::cout << "Failed: -4, -6" << std::endl;
			return -3;
		}
	} else if(atoi(argv[1]) == 4){
		std::cout << std::endl << "Testing Q4" << std::endl;
		bool a, b;
		a = true;
		b = true;
		test.q4(a,b);
		std::cout << std::endl;
		
		b = false;
		test.q4(a,b);
		std::cout << std::endl;
		
		test.q4(b,a);
		std::cout << std::endl;
		
		a = false;
		test.q4(b,a);
		std::cout << std::endl;
	} else if(atoi(argv[1]) == 5){
		std::cout << std::endl << "Testing Q5" << std::endl;
		test.q5();
		std::cout << std::endl;
	} else {
		std::cout << "Regarding your selection of " << argv[1] << std::endl;
		std::cout << "Invalid selection of question to test. ";
		std::cout << "Please input a number from 0 to 5 (inclusive)." << std::endl;
	}

}
