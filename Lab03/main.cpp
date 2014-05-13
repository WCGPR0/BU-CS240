#include <iostream>
#include "Bag.h"

int main(int argc, char *argv[]){
	std::cout << "1: Testing default bag" << std::endl;
	Bag bag1();
	std::cout << "2: Testing bag with 1" << std::endl;
	Bag bag2(1);
	std::cout << "3: Testing bag with 1,2" << std::endl;
	Bag bag3(10,5);
	std::cout << "4: Testing bag with bag3" << std::endl;
	Bag bag4(bag3);
	std::cout << "5: Testing bag1 = bag4" << std::endl;
	Bag* bagpointer;
	bagpointer = &bag4;
	std::cout << "6: Testing bag1.push_back(4)" << std::endl;
	bag3.push_back(4);
	std::cout << "7: Testing bag1.pop_back()" << std::endl;
	bag3.pop_back();
	std::cout << "8: Testing bag1[2] and << " << std::endl;
	std::cout << bag3[2] << std::endl;
	std::cout << "9: Testing further << " << std::endl;
	std::cout << bag3 << std::endl;
	std::cout << "10: Testing bag1.find(2)" << std::endl;
	std::cout << bag3.find(2) << std::endl;
	std::cout << "11: Testing bag1.clear()" << std::endl;
	bag3.clear();
	std::cout << "12: Testing bag1.empty()" << std::endl;
	std::cout << bag3.empty() << std::endl;
return 0;
}
