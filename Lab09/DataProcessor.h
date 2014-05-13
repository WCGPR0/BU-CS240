#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
class DataProcessor {
public:	
	static const size_t not_found = -1; /**< As a return, it is usually to indicate no matches found */
	/* This will take a string (lename) as an argument and read a set of data from a file and load it into the working set. After a call to this function,the entire data contents of the le will be the only things in the working set. The file will consist of foating point numbers, one per line. */
	void readFromFile(std::string fileName);
	/* This will take a string ( filename) as an argument and write the current working set of data to a file, then resetting the working set back to empty. The file will consist of floating point numbers, one per line. */
	void writeToFile(std::string fileName);
	/* This will take a oating point value as an argumet and perform a linear search of the data for the element, returning that element's location if found. If the element is not found, return 1 DataProcessor::not found. */
	int linearSearch(const float searchElement);
	/* This will take a foating point value as an argument and perform a binary search of the data for the element, returning the element's location if found. If the element is not found, return DataProcessor::not found. */
	int binarySearch(const float searchElement);
	/* This will sort the data in the vector using a "slow" sort that you have implemented in this assignment. This sort is required to have an average-case runtime of O(n2). */
	void slowSort();
	/* This will sort the data in the vector using a "fast" sort that you have implemented in this assignment. This sort is required to have an average-case runtime of O(n*lg(n)) */     
	void fastSort();
	
	/** Overloads the ostream operator << */
	friend std::ostream& operator << (std::ostream& stream, const DataProcessor& dp);
private:
	std::vector<float> workingSet; /**< This is the vector<float> data */
};
#endif
