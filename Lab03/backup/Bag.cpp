#include "Bag.h"
using namespace std;

Bag::Bag(){
items = NULL;
itemSize = 0;
itemCapacity = 0;
}

Bag::Bag(int itemCapacity, int itemSize = 0) : itemCapacity(itemCapacity), itemSize(itemSize) {
items = new Element[itemCapacity];
}

Bag::Bag(const Bag& rhs){
	for (int i=0; i < rhs.itemSize; i++)
		items[i]=rhs.items[i];
	itemSize = rhs.itemSize;
	itemCapacity = rhs.itemCapacity;	
}

Bag& Bag::operator=(const Bag& rhs){
/*if (this == &rhs) return *this;

	//Creates a deep copy
	for (int i=0; i < rhs.itemSize; i++)
		items[i]=rhs.items[i];
	itemSize = rhs.itemSize;
	itemCapacity = rhs.itemCapacity;	
return *this;*/
return *this;
}

Bag::~Bag(){
cout << "Deconstructor called" << endl;
delete[] items;
}

void Bag::push_back(Element e) {
if (itemSize < itemCapacity)
{
	this[itemSize] = e;
	itemSize++;
}
else if (itemSize == itemCapacity)
{
	if (itemCapacity == 0) 
		itemCapacity += 1;
	else 
		itemCapacity *= 2; 
	//Copies a temporary new array
	Element* tempItems = new Element[itemCapacity];
	for (int i=0; i < itemSize; i++)
	{
	tempItems[i] = items[i];
	}
	delete[] items;
	items = tempItems;
	itemSize++;
}
else return; //ERROR: itemCapacity > itemSize
}

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

Element& Bag::operator[](int i) const{
return items[i];
}
int Bag::find(Element e) const{
	for (int i=0; i < itemSize; i++)
		if (items[i] == e) return i;
	return -1;
}
int Bag::size() const{
	return itemSize;
}
int Bag::capacity() const{
	return itemCapacity;
}
//Precondition: assert itemSize > 0, and is an accurate size of items
void Bag::clear(){
	std::fill(items, items + itemSize, 0);	
}
bool Bag::empty() const{
	for (int i=0; i<itemSize; i++)
		if (items[i] !=0) return false;
	return true;
}

ostream& operator<<(std::ostream os, const Bag& b){
os << "\n" << b.size() << " items:";
	for (int i=0; i<b.size(); i++)
		os << " " << b[i];
	os << endl;
}
