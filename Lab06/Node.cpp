#include "Node.h"

/** This initializes the data members of the Node class. This should not make any allocations. 
*/
Node::Node(){
next = nullptr;
data = nullptr;
}

/** This should take in an Element by value, allocate space for a copy of that value and store that location.
*/
Node::Node(const Element& someElement){
if (&someElement != nullptr)
data = new Element(someElement);
next = nullptr;
}

/** One of the big Threes: Copy Constructor */
Node::Node(const Node& someNode){
data = new Element(someNode.getElement());

if (someNode.hasNext()) {
	Node newNode(someNode.getElement());
	Node* nodePointer = &newNode;
	setNext(nodePointer);

	for (Node* tmpNode = someNode.getNext(); tmpNode != nullptr; tmpNode = tmpNode->next)
	{

	//Element could be null
	nodePointer->setNext(new Node(tmpNode->getElement()));

	nodePointer = nodePointer->next;
	}
	}
else next = nullptr;

}




/** One of the big Threes: Assignment Operator */
Node& Node::operator=(const Node& someNode){
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
Node::~Node(){
for (Node* myPtr = this; myPtr != nullptr; myPtr=myPtr->next)
{
	delete myPtr->data;
}
}

/** Determines if a Node has another Node linked to it
*/
const bool Node::hasNext() const{
	return (next != nullptr);
}

/** Sets a Node's link to the Node whose location is passed as an argument
*/
void Node::setNext(Node* someNode) {
next = someNode;
}

/** Returns the location of the Node that is directly linked with this one
*/
Node* Node::getNext() const{
return next;
}

/** Returns the value of the Element stored in the Node 
*/
//Note: Consider using nullable?
Element Node::getElement() const{
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
