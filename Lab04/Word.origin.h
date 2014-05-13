#ifndef WORD_H
#define WORD_H

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;
class Word {
	public:
		Word(ifstream* myString);
		friend ostream& operator <<(ostream& out, const Word& word);
		friend ofstream& operator <<(ofstream& out, const Word& word);
		int replaceWords(const string& replaceFrom, 
					const string& replaceTo);
		int replace(const string& replaceFrom, 
					const string& replaceTo);
	private:
		string myString;
		void init();
		bool letterCheck(size_t myPos);
};

#endif
