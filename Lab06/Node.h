#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
typedef float Element;
class Node {
	private:
		Element* data;
		Node* next;

	public:
		//! Default Value Constructor	
		Node();
		//! Explicit Value Constructor
		//! @param someElement constant Element reference
		Node(const Element& someElement);
		//! Copy Constructor
		//! @param someNode constant Node reference 
		Node(const Node& someNode);
		//! Overloaded Copy Assignment
		//! @param someNode constant Node reference
		Node& operator=(const Node& someNode);
		//! Deconstructor
		~Node();
		//! Predicate method to validate if next is pointed to something
		//! @return b a boolean value, true if it's not pointed to a null pointer
		const bool hasNext() const;
		//! Sets the next pointer to some other Node
		//! @param someNode pointer
		void setNext(Node* someNode);
		//! Accessor method to get the next pointer
		//! @return c a Node reference	
		Node* getNext() const;
		//! Accessor method to get the current Element
		//! @return e an Element type	
		Element getElement() const;
		friend std::ostream& operator<<(std::ostream& os, const Node& someNode); //Output overloading
};
#endif
