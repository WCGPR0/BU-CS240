#include "Node.h"

/** This initializes the data members of the Node class. This should not make any allocations. 
*/
template <typename Element>
Node<Element>::Node(){
next = nullptr;
data = nullptr;
}

/** This should take in an Element by value, allocate space for a copy of that value and store that location.
*/
template <typename Element>
Node<Element>::Node(const Element& someElement){
if (&someElement != nullptr)
data = new Element(someElement);
next = nullptr;
}

/** One of the big Threes: Copy Constructor */
template <typename Element>
Node<Element>::Node(const Node& someNode){
data = new Element(someNode.getElement());

if (someNode.hasNext()) {
	Node newNode(someNode.getElement());
	Node* nodePointer = &newNode;
	setNext(nodePointer);

	for (Node* tmpNode = someNode.getNext(); tmpNode != nullptr; tmpNode = tmpNode->next) {

		//Element could be null
		nodePointer->setNext(new Node(tmpNode->getElement()));

		nodePointer = nodePointer->next;
		}
	}
else next = nullptr;

}




/** One of the big Threes: Assignment Operator */
template <typename Element>
Node<Element>& Node<Element>::operator=(const Node<Element>& someNode){
	if ((someNode.getElement() != (Element)NULL) && (this != &someNode))
	{
	for (Node* myPtr = this; myPtr != nullptr; myPtr=myPtr->next)
		delete myPtr->data;
	
	Node myNode(someNode);
	std::swap(myNode,*this);
	}
return *this;
}

/** Deconstructor */
template <typename Element>
Node<Element>::~Node(){
for (Node* myPtr = this; myPtr != nullptr; myPtr=myPtr->next)
{
	delete myPtr->data;
}
}

/** Determines if a Node has another Node linked to it
*/
template <typename Element>
const bool Node<Element>::hasNext() const{
	return (next != nullptr);
}

/** Sets a Node's link to the Node whose location is passed as an argument
*/
template <typename Element>
void Node<Element>::setNext(Node* someNode) {
next = someNode;
}

/** Returns the location of the Node that is directly linked with this one
*/
template <typename Element>
Node<Element>* Node<Element>::getNext() const{
return next;
}

/** Returns the value of the Element stored in the Node 
*/
//Note: Strings will throw an error, consider using nullable?
template <typename Element>
Element Node<Element>::getElement() const{
if (data != nullptr) 
	return *data;
else
	try {
	return (Element) 0; 
	} 
	catch (const std::exception& e)
	{
	std::cout << "Error returning 0" << std::endl;
	std::cerr << e.what();
	}
//	return	(Element)0;
}

std::ostream& operator<<(std::ostream& os, const Node& someNode){
os << "data: " << someNode.getElement()  << "\n next: ";
if (someNode.hasNext()) 
	os << someNode.next;
else os << "null";
os << std::endl;
return os;
}
