#include "Word.h"

Word::Word(ifstream* myString){
	string temp;
	bool flag = false;
	while (getline(*myString, temp))
	{
		if (flag) this->myString += "\n" + temp;
		else 	{	
			this->myString += temp; 
			flag = !flag;
		}
	}
	init();
}

int Word::replaceWords(string replaceFrom, string replaceTo, int size){
	int counter = 0, i = 0;
	size_t startPos;
	while((startPos = myString.find(replaceFrom,i)) != string::npos) {
		i = startPos + 1;
		if (((letterCheck(startPos+size))) && ((letterCheck(startPos-1))));
		{
			cout << "CHAR AT " << size << " IS " << myString.at(startPos+size);
			myString.replace(startPos, size, replaceTo);
			counter++;
		}
	}
	return counter;
}

int Word::countWords(string countFrom, string countTo){
	int counter = 0, i = 0;
	size_t startPos;
	while((startPos = myString.find(countFrom,i)) != string::npos) {
		i = startPos + 1;
		if (stopCheck(startPos+countFrom.length()+1));
		{		
			counter++;
		}
	}
	return counter;
}
//ASsuming an ASCII Table
bool Word::letterCheck(size_t myPos){
	/*return (((myString.at(myPos) >= 65)
	  && myString.at(myPos) <= 90)
	  || ((myString.at(myPos) >=97)
	  && (myString.at(myPos) <=122)));
	 */
	return myString.at(myPos) == 0x20; // myString.at(myPos)  == ' ';
}

bool Word::stopCheck(size_t myPos){
	return ((myString.substr(myPos, 1) == "A") ||
			(myString.substr(myPos, 2) == "an") ||
			(myString.substr(myPos, 2) == "An") ||
			(myString.substr(myPos, 3) == "and") ||
			(myString.substr(myPos, 3) == "And") ||
			(myString.substr(myPos, 3) == "are") ||	
			(myString.substr(myPos, 3) == "Are") ||
			(myString.substr(myPos, 2) == "be") ||
			(myString.substr(myPos, 2) == "Be") ||
			(myString.substr(myPos, 2) == "he") ||
			(myString.substr(myPos, 2) == "is") ||
			(myString.substr(myPos, 2) == "Is") ||
			(myString.substr(myPos, 2) == "it") ||
			(myString.substr(myPos, 2) == "It") ||
			(myString.substr(myPos, 3) == "she") ||
			(myString.substr(myPos, 3) == "She") ||
			(myString.substr(myPos, 3) == "the") ||
			(myString.substr(myPos, 3) == "The") ||
			(myString.substr(myPos, 3) == "you") ||
			(myString.substr(myPos, 3) == "You")
	       );
}	

int Word::replace(const string& replaceFrom, const string& replaceTo, int size){
	int counter = 0, i = 0;
	size_t startPos;
	while ((startPos = myString.find(replaceFrom, i)) != string::npos) {
		i = startPos + 1;
		myString.replace(startPos, replaceFrom.length(), replaceTo);
		counter++;	
	}	
	return counter;
}

void Word::init(){
	int wordsChanged = 0, wordsCounted;
	string badWords[] = {"War", "Martians", "died", "die", "gun", "water", "people"};
	string goodWords[] = {"Rainbows", "witches", "laughed", "laugh", "puppy", "lemonade", "children"}; string badText[] = {"dark", "blood", "destroy"}; string goodText[] = {"bright", "strawberry syrup", "mend"};
	for (int i = 0; i < 7; i++)
	{
		wordsChanged += replaceWords(badWords[i],goodWords[i],badWords[i].size());
		wordsCounted += countWords(badWords[i],goodWords[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		wordsChanged += replace(badText[i],goodText[i], badText[i].size());
		wordsCounted += countWords(badText[i],goodText[i]);
	}
	double replacedWords = replaceWords(" ", " ", 1);
	double changed = (double) wordsChanged / replacedWords;
	cout << changed * 100 << endl;
	changed = (double) wordsChanged / (double) wordsCounted;
	cout << changed * 100 << endl;
}

ostream& operator<< (ostream& out, const Word& word){
	out << word.myString;
	return out;
}

ofstream& operator<< (ofstream& out, const Word& word) {
	out << word.myString;
	return out;
}
