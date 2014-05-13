#include "ClassB.h"
using namespace std;

/** Euclidean Algorithm, function gcd */
	int gcd(int A, int B) {

		if (B==0)
			return A;
		else 
			return gcd(B, A % B);
	}

	//precondition: sizeOfArray = size of array: myArray[]
/** Prints out myArray[], replacing occurances of N with M */
	void ClassB::q1(int myArray[], int sizeOfArray, int N, int M){
//	assert((sizeOf(myArray)/sizeof(int))==sizeOfARray);
	if (myArray == NULL) return;
	for (int i = 0; i < sizeOfArray; i++)
	{
	if (myArray[i]==N) cout << M;
	else
	cout << myArray[i];
	cout << " ";
	}
	
	cout << endl;
	}
	
/** Prints even integers from A to B (Exclusive) */
	void ClassB::q2(int A, int B) {
//	assert(A<=B);
	A+=1;
	if ((A % 2) != 0) A++;
	for (int i = A; i < B; i+=2) {
	cout << i << endl;
	}
	}

/** Returns the least common multiple of A and B */
	int ClassB::q3(int A, int B) {
	int gcdResult;
	if (A <= 0 || B <= 0) return -1;
	if (A > B) gcdResult = gcd(A, B);
	else gcdResult = gcd(B, A);
	if (gcdResult == 0) return -1;
	else
	return (A * B) / gcdResult;	
	}

/** Compares two boolean values with various logic statements */
	void ClassB::q4(bool A, bool B) {
	cout << boolalpha << "AND " << (A && B) << endl
	<< "OR " << (A || B) << endl
	<< "NAND " << (!(A && B)) << endl
	<< "NOR " <<  (!(A || B)) << endl
	<< "XOR " << toString(A ^ B) << endl
	<< "IMPL " << (!A || B) << endl
	<< "EQU " << (A == B) << endl;
	}

/** Prints Fizz every 5 count, and Buzz every 9 count */
	void ClassB::q5() {
	for (int i = 1; i <= 100; i++) {
	if ((i % 5)!=0 && (i % 9) !=0) {cout << i << endl; continue;}
	else if ((i % 5)==0) cout << "Fizz";
	if ((i % 9)==0) cout << "Buzz";
	cout << endl;		
	}
	}

//converts a bool value to a string that expresses that value
//without this function, printing the bool will print either 0 or 1
const char* ClassB::toString(bool x){ 
	return x ? "true" : "false";
}
