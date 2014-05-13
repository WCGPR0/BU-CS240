#include "Bag.h"
using namespace std;

/**Default Constructor*/
Bag::Bag(){
items = nullptr;
itemSize = 0;
itemCapacity = 0;
}

/**Explicit Constructor*/
Bag::Bag(int itemCapacity, int itemSize) : itemCapacity(itemCapacity), itemSize(itemSize) {
	if(itemCapacity > 0) items = new Element[itemCapacity];
	else {
	this->itemSize=0;
	this->itemCapacity=0;
	}
}

/**Copy Constructor*/
Bag::Bag(const Bag& rhs) {
	if ((rhs.itemSize > rhs.itemCapacity)) throw logic_error("itemSize > itemCapacity");
	if ((rhs.itemSize <= 0) || (rhs.itemCapacity <= 0)) {
	items = nullptr;
	itemSize =0;
	itemCapacity =0;
	}
	else {
	itemSize = rhs.itemSize;
	itemCapacity = rhs.itemCapacity;
	items = new Element[itemCapacity];
	for (int i=0; i < rhs.itemSize; i++)
		items[i]=rhs.items[i];
	}
}

/**Overloading assignment operator*/
Bag& Bag::operator=(const Bag& rhs){
	if (rhs.itemSize > rhs.itemCapacity) throw logic_error("itemSize > itemCapacity");

if (this == &rhs) return *this;

	itemSize = rhs.itemSize;
	itemCapacity = rhs.itemCapacity;
	
	if (itemSize >= 0) {
	items = new Element[itemCapacity];
	for (int i=0; i < rhs.itemSize; i++)
		items[i]=rhs.items[i];
	}
	
return *this;
}

/**Deconstructor*/
Bag::~Bag(){
	cout << "Deconstructor called" << endl;
	delete[] items;
}

/**Reallocate the Element array, and increases size if stack is full*/
void Bag::push_back(Element e) {
	//Preconditions
	if (itemSize > itemCapacity) throw logic_error("itemSize > itemCapacity");
	if ((itemSize < 0) || (itemCapacity < 0)) throw out_of_range("negative itemSize/Capacity");

	if (itemSize < itemCapacity) {	

	items[itemSize] = e;
	itemSize++;

	}
	else //if (itemSize == itemCapacity)
	{
	if (itemCapacity == 0) {
		itemCapacity += 1;
	}	
	else {
		itemCapacity *= 2;
		}
	Element* tempItems = new Element[itemCapacity];
	//Copies a temporary new array	
	for (int i=0; i < itemSize; i++)
	{
		tempItems[i] = items[i];
	}
	//delete[] items;
	items = tempItems;
	//items[itemSize] = e;
	itemSize++;
	}
//else return; //ERROR: itemCapacity > itemSize
}

/** Takes the last element, if exists, returns it and pops stack by one */
//Precondition: assert itemSize and itemCapacity does not exceed CLIMITS
Element Bag::pop_back(){
if (itemSize > 0) {
	Element e = items[itemSize--];
	//Copies a temporary new array
	Element* tempItems = new Element[itemCapacity];
	for (int i=0; i < itemSize; i++)
		tempItems[i] = items[i];
	delete[] items;
	items = tempItems;
return e;
}
else if (items == 0) throw std::length_error("Can't pop back an empty array");
else throw std::out_of_range("Element size too big");
}

/** Overloads array subscript to easily index Element */
Element& Bag::operator[](int i) const{
if (i > itemSize-1) throw std::out_of_range("You're accessing out of range"); 
else return items[i];
}

/** Returns the nth position of first element, e, found */
int Bag::find(Element e) const{
	for (int i=0; i < itemSize; i++)
		if (items[i] == e) return i;
return -1;
}

/** Returns the itemSize */
int Bag::size() const{
return itemSize;
}

/** Returns the itemCapacity */
int Bag::capacity() const{
return itemCapacity;
}

/** Clears Element array with 0s */
//Precondition: assert itemSize > 0, and is an accurate size of items
void Bag::clear(){
	//std::fill(items, items + itemSize, nullptr);	
	/*for (int i =0; i < itemSize; i ++)
	items[i] = nullptr;
	itemSize = 0;*/
	if (itemSize !=0) delete[] items;
	items = new Element[itemCapacity];
	itemSize = 0;
}

/** Checks if Element array is filled with 0s */
bool Bag::empty() const{
	if (itemSize == 0) return true;
	else return false;
}

/** Compares two bags if they are equal */
bool Bag::operator== (Bag bag) const {
if ((itemSize == bag.size()) && itemCapacity == bag.capacity())
{
	for (int i=0; i< itemSize; i++)
	if (!(items[i] == bag[i])) return false;
return true;
}
else return false;
}

/** Compares two bags if they are not equal */
bool Bag::operator!= (Bag bag) const {
return !(operator==(bag));
}

/** Overloads the ostream, outputting the items */
ostream& operator<<(std::ostream &os, const Bag& b){
os << "\n" << b.size() << " items:";
	for (int i=0; i<b.size(); i++)
		os << " " << b[i];
	os << endl;
return os;
cout << "PUSH BACK CALLED" ;}
