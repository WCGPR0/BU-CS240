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

int Word::replaceWords(const string& replaceFrom, const string& replaceTo){
	int counter = 0, i = 0;
	size_t startPos;
	while((startPos = myString.find(replaceFrom,i)) != string::npos) {
	i = startPos + 1;
	if (!((myString.at(startPos-1))) && !((myString.at(startPos-1))));
	{
	myString.replace(startPos, replaceFrom.length(), replaceTo);
	counter++;
	}
	}
	return counter;
}

//ASsuming an ASCII Table
bool Word::letterCheck(size_t myPos){
return (((myString.at(myPos) >= 65)
	&& myString.at(myPos) <= 90)
	|| ((myString.at(myPos) >=97)
	&& (myString.at(myPos) <=122)));
}	

int Word::replace(const string& replaceFrom, const string& replaceTo){
	int counter = 0, i = 0;
	while( size_t startPos = myString.find(replaceFrom, i) != string::npos) {
	i = startPos + 1;
	myString.replace(startPos, replaceFrom.length(), replaceTo);
	counter++;	
}	
	return counter;
}

void Word::init(){
int wordsChanged = 0;
string badWords[] = {"War", "Martians", "died", "die", "gun", "water", "people"},
	goodWords[] = {"Rainbows", "witches", "laughed", "laugh", "puppy", "lemonade", "children"}, badText[] = {"dark", "blood", "destroy"}, goodText[] = {"bright", "strawberry syrup", "mend"};

	for (int i = 0; i < 7; i++)
		wordsChanged += replaceWords(badWords[i],goodWords[i]);
	for (int i = 0; i < 3; i++)
		wordsChanged += replaceWords(badText[i],goodText[i]);

double replacedWords = replaceWords(" ", " ");
double changed = (double) wordsChanged / replacedWords;
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
