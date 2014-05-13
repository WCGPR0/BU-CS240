#include "Node.h"

/** Default Constructor */
Node::Node(){
next = nullptr;
data = nullptr;
}

/**Explicit Constructor */
Node::Node(const Element& someElement){
if (&someElement != nullptr)
data = new Element(someElement);
next = nullptr;
}

/** Copy Constructor */
Node::Node(const Node& someNode){
data = new Element(someNode.getElement());

if (someNode.hasNext()) {
	Node newNode(someNode.getElement());
	Node* nodePointer = &newNode;
	setNext(*nodePointer);

	for (Node* tmpNode = &someNode.getNext(); tmpNode != nullptr; tmpNode = tmpNode->next)
	{

	//Element could be null
	nodePointer->setNext(*new Node(tmpNode->getElement()));

	nodePointer = nodePointer->next;
	}
	}
else next = nullptr;

}




/** Copy Assignment */
Node& Node::operator=(const Node& someNode){
	if ((someNode.getElement() != NULL) && (this != &someNode))
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


const bool Node::hasNext() const{
	return (next != nullptr);
}

void Node::setNext(Node& someNode) {
next = &someNode;
}

Node& Node::getNext() const{
return *next;
}

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
