/** Reverse Polish Notation Calculator
	Question 3.1
	Victor Wu
	CS240
	*/

#include <stack>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <limits>
using namespace std;


//Precondition: No negative integers (it'll just treat it as a minus operator)
void RPNCalculator(istream& ss, stack<string>& s) {
	string token;
	if (getline(ss,token, ',')) {
		//If token is an operand
		if ((token[0] == '+') || (token[0] == '-') || (token[0] == '*') || (token[0] == '/')){	
			//Pop the first two, perform operation, and push back
			assert(s.size() >= 2);	
			double x, y;
			x = stod(s.top());
			s.pop();
			y = stod(s.top());
			s.pop();
			switch (token[0]) {
				case '+': s.push(to_string(y+x)); break;
				case '-': s.push(to_string(y-x)); break;
				case '*': s.push(to_string(y*x)); break;
				case '/': s.push(to_string(y/x)); break;	
				}
			}
		else {
			// Push it onto the stack
			double x;
			x= stod(token);	
			s.push(to_string(x));
		}
	//Recursion: Repeat till end of string
	RPNCalculator(ss, s);
}
}

int main(int argc, char* argv[]) {
	stringstream ss;
	if (argc == 2) ss.str(argv[1]);
	else if (argc == 1) ss << skipws << cin.rdbuf();
		else {cerr << "Invalid arguments" << endl; return -1;}
	cout << "The equation you input is: " << argv[1] << endl;
		//Initialize an empty stack	
/* Using a stack STL because the algorithm for RPN is a stack implementation */
		stack<string> s;
	
		//Modifies stack	
		RPNCalculator(ss, s);

		if (s.size() == 1) {
			double calcValue = stod(s.top());
			cout << calcValue << endl;
			if (calcValue == numeric_limits<double>::infinity()) cerr << "Warning: Overflowed.";
		
			return 0;	
		}
		else  {
			cerr << "Invalid RPN expression." << endl;
		return -1;
		}
}
