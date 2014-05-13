/** Victor Wu
  CS 240
 */
#include "DataProcessor.h"
#define MAX_CHARS (sizeof(float)*4)

/** Reads floating points from a file, and puts it into the working set.
  @param fileName, a string argument for the name of the file */
void DataProcessor::readFromFile(std::string fileName){
	std::fstream myFile(fileName,std::fstream::in);
	if (myFile.fail()) std::cerr << "Error opening file" << std::endl;
	char tempString[MAX_CHARS];
	if (!workingSet.empty()) workingSet.clear();
	while (myFile.getline(tempString,MAX_CHARS))
		try{
			workingSet.push_back(std::stof(tempString));		
		}
	catch(...){
		std::cerr << "Invalid Input; Floats only please" << std::endl;
		return;
	}	
	myFile.close();
}

/** Writes floating points from the working set, and puts it in the file.
  @param fileNAme, a string argument for the name of the file */
void DataProcessor::writeToFile(std::string fileName){
	std::ofstream myFile(fileName,std::ofstream::out);
	if (myFile.fail()) std::cerr << "Error" << std::endl;
	for (std::vector<float>::const_iterator i = workingSet.begin(); i != workingSet.end(); ++i)
		myFile << *i << std::endl;
	myFile.close();
}

/** Performs a linear search on the working set, with time complexity: O(n).
  @param searchElement, a float argument for the value to be searched.
  @return an int representing the position of the found element */
int DataProcessor::linearSearch(float searchElement){
	int counter = 0;
	if (workingSet.empty()) return not_found;
	while ((workingSet[counter++] != searchElement) && (workingSet[counter] != NULL
				)) {
	}
	return (workingSet[--counter] == searchElement) ? counter : not_found;
}

/* Implementation of helper function: binary search algorithm */
int binary_search(std::vector<float>& V, float searchElement, int min, int max)
{
	if (min > max) return DataProcessor::not_found;
	else {
		int mid = (min + max) / 2;
		if (V[mid] < searchElement)
			return binary_search(V, searchElement, mid+1, max);
		else if (V[mid] > searchElement)
			return binary_search(V, searchElement, min, mid-1);
		else	return mid;
	}
}

/** Performs a binary search on the working set, with time complexity: O(log n).
  @param searchElement, a float argument for the value to be searched.
  @return an int representing the position of the found element */
int DataProcessor::binarySearch(float searchElement){
	if (workingSet.empty()) return -1;
	else return binary_search(workingSet, searchElement, 0, workingSet.size());
}

/** Performs a variation of the Bubble sort on the working set, with time complexity: O(n^2). */
void DataProcessor::slowSort(){
	/* Implementing Cocktail shaker sort algorithm - Bubble Sort variation
References: http://en.wikipedia.org/wiki/Cocktail_shaker_sort#Pseudocode 
	 */
	int start = 0, end = workingSet.size()-1;
	bool swapped;

	//Already sorted if true
	if (end <= 1) return;

	do {
		swapped = false;
		// We know that the First element is sorted already (Upwards bubble sort)
		for (int i = start++; i < end; i++) {
			if (workingSet[i] > workingSet[i+1]) {
				//Swaps
				float temp = workingSet[i+1];
				workingSet[i+1] = workingSet[i];
				workingSet[i] = temp;
				swapped = true;
			}
		}
		if (!swapped) break;
		swapped = false;
		// We know that the Last element is sorted already (Reverse bubble sort)
		for (int i = --end; i >= start; i--) {
			if (workingSet[i] < workingSet[i-1]) {
				//Swaps
				float temp = workingSet[i-1];
				workingSet[i-1] = workingSet[i];
				workingSet[i] = temp;
				swapped = true;
			}
		}
	}
	while (swapped);
}


/** Implementing in-place partition alogrithm
References: http://en.wikipedia.org/wiki/Quicksort#In-place_version */
int partition (std::vector<float>& workingVector, int left, int right, int pivotIndex){
	float pivotValue = workingVector[pivotIndex];
	std::swap(workingVector[pivotIndex], workingVector[right]);
	for (int i = left; i < right-1; i++)
		if (workingVector[i] <= pivotValue){
			std::swap(workingVector[i], workingVector[left]);
			left++;
		}
	std::swap(workingVector[left],workingVector[right]);
	return left;
}

/* Implementing Quicksort algorithm
References: http://en.wikipedia.org/wiki/Quicksort#In-place_version */
void quicksort(std::vector<float>& workingVector, int left, int right) {
	if (left < right) {
		//Choosing pivot index as the median of the first, middle, and last
		int middle = (left + right) / 2;
		int pivotIndex = ((workingVector[left] >= workingVector[middle]) && (workingVector[left] <= workingVector[right])) || ((workingVector[left] >= workingVector[right]) && (workingVector[left] <= workingVector[middle])) ? left : ((workingVector[middle] >= workingVector[left]) && (workingVector[middle] <= workingVector[right])) || ((workingVector[middle] >= workingVector[right]) && (workingVector[middle] <= workingVector[left])) ? middle : right;
		// Calls and sorts array of bigger and smaller items, and get final position, of pivot
		int newPivotIndex = partition(workingVector, left, right, pivotIndex);
		//Recursive sorting of elements smaller than pivot
		quicksort(workingVector, left, newPivotIndex-1);
		//Recursive sorting of elements larger than pivot
		quicksort(workingVector, newPivotIndex+1, right);
	}

}

/** Performs a quick sort on the working set, with time complexity: O(n log n). */
void DataProcessor::fastSort(){
	//int depth_limit = 2*(log(workingSet.size())); //Introsort condition (change to heap)
	quicksort(workingSet, 0, workingSet.size()-1);
}

// Overloading ostream << opeartor
std::ostream& operator<<(std::ostream& stream, const DataProcessor& dp) {
	for (std::vector<float>::const_iterator i = dp.workingSet.begin(); i != dp.workingSet.end(); ++i)
		stream << *i << std::endl;
	return stream;
}
