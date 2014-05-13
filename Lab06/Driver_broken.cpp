#include "LinkedList.h"
#include <iostream>
using namespace std; 

int main(int argc, char* argv[]) {
cout << "Constructing empty list: \n" << endl;
LinkedList* list1 = new LinkedList();
cout << *list1 << endl;

cout << "Checking if empty list is empty: \n" << endl;
cout << list1->empty() << endl;

cout << "Inserting element 5.0 in front: \n" << endl;
Element e = 5.0;
list1->insertFront(e);

cout << "Inserting element 6.0 in back: \n" << endl;
e = 6.0;
list1->insertBack(e); //Error here

cout << "Removing element from the front: \n" << endl;
list1->removeFront();

cout << "Removing element from the back: \n" << endl;
list1->removeBack();

cout << "Adding element 3.0 at index 5: \n" << endl;
e = 3.0;
list1->insertAt(e,5);

cout << "Finding element 3.0: \n" << endl;
list1->find(e);

cout << "Removing element at index 5: \n" << endl;
cout << list1->removeAt(5);

delete list1;
}
