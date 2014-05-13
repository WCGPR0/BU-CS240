#include <iostream>
#include <cstdio>
#include "Word.h"
#include <fstream>
#include <assert.h>

int main(int argc, char* argv[])
{
//Assertions
assert(argc == 3);

string input = argv[1];
string output = argv[2];

std::ifstream inStream(input, std::ifstream::in);
std::ofstream outStream(output, std::ofstream::out);

//Assertions
assert(outStream.is_open());
if (inStream.good() != true)
return -1;

else{
Word word(&inStream);
outStream << word;

}
inStream.close();
outStream.close();
}
