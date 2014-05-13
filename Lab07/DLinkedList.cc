/** Create an empty list
*/
template <typename Element>
DLinkedList<Element>::DLinkedList() : firstNode(nullptr), lastNode(nullptr), nodeSize(0){
}

/** Deconstructs LinkedList
*/
template <typename Element>
DLinkedList<Element>::~DLinkedList() {
	Node<Element> *tempPointer = firstNode;
	Node<Element> *tempPPointer;
	while (tempPointer != nullptr) {
		if (tempPointer->hasNext()) {
			tempPPointer =  &(tempPointer->next);
			delete tempPointer;
			tempPointer = tempPPointer;
			}
		else delete tempPointer;
	}
}

/** Check if the list is empty
*/
template <typename Element>
bool DLinkedList<Element>::empty() const{
	return nodeSize == 0;	
}

/** Insert an item into the list
*/
template <typename Element>
void DLinkedList<Element>::insert_first(Element e){
	NodePointer myNode = new Node(e);
	myNode->setNext(firstNode);
	firstNode = myNode;
	nodeSize++;	
}

/** Insert an item into the list
*/
template <typename Element>
void DLinkedList<Element>::insert_last(Element e){
	NodePointer myNode = new Node(e);
	myNode->setNext(nullptr);

	if (firstNode == nullptr){
		firstNode = myNode;
		myNode->setNext(nullptr);
	}
	else {
		NodePointer lastNodePointer = firstNode;
		while ((lastNodePointer->hasNext()) && (lastNodePointer->getNext() != lastNodePointer)) lastNodePointer = lastNodePointer->getNext();
		lastNodePointer->setNext(myNode);
	}
	nodeSize++;	
}

/** Remove an item from the list
*/
template <typename Element>
Element DLinkedList<Element>::delete_first(){
	if (nodeSize > 0) {
		NodePointer tempNode = firstNode;	
		Element tempElement = firstNode->getElement();
		firstNode = firstNode->getNext();
		delete tempNode;
		nodeSize--;
		return tempElement;	
	}	
	else return (Element)NULL;		
	}

/** Remove an item from the list
*/
template <typename Element>
Element DLinkedList<Element>::delete_last(){
	if (nodeSize > 0) {
		NodePointer lastNodePointer = firstNode;
		if (firstNode->hasNext()) {	
			while ((lastNodePointer->hasNext()) && (lastNodePointer->getNext() != lastNodePointer)) lastNodePointer = lastNodePointer->getNext();
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
template <typename Element>
void DLinkedList::insertAt(Element e, int i){
	if ((i == 0) || (nodeSize <= 0)) insert_first(e);
	else if (nodeSize < i) insert_last(e);
	else {
		int counter = 0;
		for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = tempNodePointer->getNext()) {
			if (i == counter) {
				NodePointer myNode = new Node(e);
				myNode->setNext(tempNodePointer->getNext());
				tempNodePointer->setNext(myNode);
				nodeSize++;
			}
			counter++;
		}
	}
}

/** This inserts a Node with Element e at position i if such a position exists (uses 0-based indexing)
*/
template <typename Element>
Element DLinkedList::removeAt(int i){
	if (nodeSize > 0) {
		if (i <= 0) return delete_first();
		else if (nodeSize < i) return delete_last();
		else {
		int counter = 0;	
		for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = tempNodePointer->getNext()) {
			if (counter == (i-1)) {
				NodePointer delNode = tempNodePointer->getNext();
				Element tempElement = delNode->getElement();
				if (tempNodePointer->getNext()->hasNext()) {
					tempNodePointer->setNext(tempNodePointer->getNext()->getNext());
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
template <typename Element>
int DLinkedList::find(Element e) const{
	int counter = 0;
	for (NodePointer tempNodePointer = firstNode; tempNodePointer != nullptr; tempNodePointer = tempNodePointer->getNext()) {
		if (tempNodePointer->getElement() == e) return counter;
	}
return -1;
}

/** Deletes any element from the list that contains the passed value,
and returns the count of elements that have been deleted
*/
template <typename Element>
int DLinkedList<Element>::delete_value(Element e) {
	int found = 1;
	int counter = 0;
	while (found != -1) {
		found = find(e);
		removeAt(e);
		counter++;
	}
	return counter;
}

/** Counts how many data elements are contained in the linked list
*/
template <typename Element>
int DLinkedList<Element>::count() const{
	return nodeSize;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& someList){
int counter = 0;
for (Node* tempNodePointer = someList.firstNode; tempNodePointer != nullptr; tempNodePointer = tempNodePointer->getNext()) {
	os << "Node Index: " << counter << "\t Node Element: " << tempNodePointer->getElement()  << "\n";
	counter++;
}
os << std::endl;
return os;
}
