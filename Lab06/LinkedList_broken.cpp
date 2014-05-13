#include "LinkedList.h"

/** Create an empty list
*/
LinkedList::LinkedList() : firstNode(nullptr), nodeSize(0){
}

/** Deconstructs LinkedList
*/
LinkedList::~LinkedList() {

}

/** Check if the list is empty
*/
bool LinkedList::empty() const{
	return nodeSize == 0;	
}

/** Insert an item into the list
*/
void LinkedList::insertFront(Element e){
	NodePointer myNode = new Node(e);
	myNode->setNext(*firstNode);
	firstNode = myNode;
	nodeSize++;	
}

/** Insert an item into the list
*/
void LinkedList::insertBack(Element e){
	NodePointer myNode = new Node(e);
	myNode->setNext(nullptr);

	if (firstNode == nullptr){
		firstNode = myNode;
		myNode->setNext(nullptr);
	}
	else {
		NodePointer lastNodePointer = firstNode;
		while (lastNodePointer != nullptr) lastNodePointer = &lastNodePointer->getNext();
		lastNodePointer->setNext(*myNode);
	}
	nodeSize++;	
}

/** Remove an item from the list
*/
Element LinkedList::removeFront(){
	if (nodeSize > 0) {
		NodePointer tempNode = firstNode;	
		Element tempElement = firstNode->getElement();
		firstNode = &firstNode->getNext();
		delete tempNode;
		nodeSize--;
		return tempElement;	
	}	
	else return (Element)NULL;		
	}

/** Remove an item from the list
*/
Element LinkedList::removeBack(){
	if (nodeSize > 0) {
		NodePointer lastNodePointer = firstNode;
		if (firstNode->hasNext()) {	
			while (lastNodePointer != nullptr) lastNodePointer = &lastNodePointer->getNext();
		}
	Element tempElement = lastNodePointer->getElement();
	delete lastNodePointer;
	nodeSize--;
	return tempElement;
	}
	else return (Element)NULL;
	
}

/** This inserts a Node with Element e at position i if such a position exists (uses 0-based indexing)
*/
void LinkedList::insertAt(Element e, int i){
	if ((i == 0) || (nodeSize <= 0)) insertFront(e);
	else if (nodeSize < i) insertBack(e);
	else {
		int counter = 0;
		for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = &tempNodePointer->getNext()) {
			if (i == counter) {
				NodePointer myNode = new Node(e);
				myNode->setNext(tempNodePointer->getNext());
				tempNodePointer->setNext(*myNode);
				nodeSize++;
			}
			counter++;
		}
	}
}

/** This inserts a Node with Element e at position i if such a position exists (uses 0-based indexing)
*/
Element LinkedList::removeAt(int i){
	if (nodeSize > 0) {
		if (i <= 0) return removeFront();
		else if (nodeSize < i) return removeBack();
		else {
		int counter = 0;	
		for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = &tempNodePointer->getNext()) {
			if (counter == (i-1)) {
				NodePointer delNode = &tempNodePointer->getNext();
				Element tempElement = delNode->getElement();
				if (tempNodePointer->getNext().hasNext()) {
					tempNodePointer->setNext(tempNodePointer->getNext().getNext());
					delete delNode;	
					return tempElement;
				}
				else if (tempNodePointer->hasNext()) {
					tempNodePointer->setNext(nullptr);
					delete delNode;
					return tempElement;
				}
				else {
					throw std::logic_error("This should NEVER happen");	
				}
			}
		counter++;
		}
		}	
	}
	else return (Element)NULL;
throw std::logic_error("This should NEVER happen");
return -1; //Some logic error for it to reach this statement
}

/** This returns the position in the List where a Node containing the provided argument is first found (-1 if not found)
*/
int LinkedList::find(Element e) const{
	int counter = 0;
	for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = &tempNodePointer->getNext()) {
		if (tempNodePointer->getElement() == e) return counter;
	}
return -1;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& someList){
int counter = 0;
for (Node* tempNodePointer = someList.firstNode; tempNodePointer != nullptr; tempNodePointer = &tempNodePointer->getNext()) {
	os << "Node Index: " << counter << "\t Node Element: " << tempNodePointer->getElement()  << "\n";
	counter++;
}
os << std::endl;
return os;
}
