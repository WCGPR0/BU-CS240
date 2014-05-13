#include "DataProcessor.h"
#include <chrono>
#include <cstdlib>
#include <fstream>


/**
	Tests DataProcessor on the speed it takes for it's searches and sorts.
	Argument 1: filename
	Argument 2: value to be searched
	Argument 3: Specify which function to call (optional)
*/
int main(int argc, char* argv[]){
	if (argc > 4) {std::cerr << "Too many inputs" << std:: endl; return -1;}
	DataProcessor* temp = new DataProcessor();
	if (argc >= 2) temp->readFromFile(argv[1]);
	srandom(time(NULL));
	float search;
	int option = 0; /**< The menu selection for testing just one search or sort */
	if (argc >= 3){
		search = std::stof(argv[2]);
		if (argc == 4) option = std::stoi(argv[3]);
	}
	else	search = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);



	bool printAll = (option == 0) ? true : false;
	if (!printAll) option = abs(option--);

	// Searching Tests
	for (int j = option; j < 2; j++) {
		double average = 0;
		int (DataProcessor::*searchFunc)(float);
		std::string helperOutput;
		switch(j){
			case (0): searchFunc = &DataProcessor::linearSearch;
				  helperOutput = "Linear Search";
				  break;
			case (1): searchFunc = &DataProcessor::binarySearch;
				  helperOutput = "Binary Search";
				  break;
			default: helperOutput = "ERROR";
				 break;
		}
		if (!printAll) j=4;
		std::cout << helperOutput << ", looking for " << search << std::endl;
		//Search tests of 10
		for (int i = 0; i < 10; i++){	
			std::chrono::monotonic_clock::time_point start = std::chrono::high_resolution_clock::now();
			(temp->*searchFunc)(search);	
			std::chrono::monotonic_clock::time_point  end = std::chrono::high_resolution_clock::now();
			//std::chrono::duration<double> elapsed_sec 
			std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			//	std::cout << elapsed.count() << " nanoseconds" << std::endl;
			average+=elapsed.count();
		}
		std::cout << "Average: " << average / 10.0 << "nanoseconds" << std::endl;
		if (!printAll) break;
	}

	if ((option > 1) && !printAll) option-=2;
	else if (!printAll) option = 2;
	// Sorting Tests

	for (int j = option; j < 2; j++) {
		double average = 0;
		void (DataProcessor::*sortFunc)();
		std::string helperOutput;
		switch(j){
			case (0): sortFunc = &DataProcessor::slowSort;
				  helperOutput = "Slow Sort";
				  break;
			case (1): sortFunc = &DataProcessor::fastSort;
				  helperOutput = "Fast Sort";
				  break;
			default: helperOutput = "ERROR";
				 break;
		}
		if (!printAll) j=4;
		std::cout << helperOutput << ", resetting file (if given)." << std::endl;
		//Sort tests of 10
		for (int i = 0; i < 10; i++){
			if (argc >= 2) temp->readFromFile(argv[1]);
			std::chrono::monotonic_clock::time_point start = std::chrono::high_resolution_clock::now();
			(temp->*sortFunc)();

			std::chrono::monotonic_clock::time_point  end = std::chrono::high_resolution_clock::now(); 
			std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			//      std::cout << elapsed.count() << " nanoseconds" << std::endl;
			average+=elapsed.count();
		}
		std::cout << "Average: " << average / 10.0 << "nanoseconds" << std::endl;	

		if (!printAll) break;
	}


	//Final Output (View working set)
	/*std::cout << "The working set is: \n" << *temp << std::endl;
	 */
	delete temp;
	return 0;
}
