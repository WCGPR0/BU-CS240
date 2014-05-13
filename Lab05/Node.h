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
		Node(); //Default Value Constructor
		Node(const Element& someElement); //Explicit Value Constructori
		Node(const Node& someNode); //Copy constructor
		Node& operator=(const Node& someNode); //Copy assignment
		~Node(); //Deconstructor
		/** Determines if a Node has another Node linked to it. */
		const bool hasNext() const;
		/** Set a Node's link to the Node whose location is passed as an argument. */
		void setNext(Node& someNode);
		/** Returns the location of the Node that is directly linked with this one */
		Node& getNext() const;
		/** Returns the value of the value of the Element stored in the Node */
		Element getElement() const;

		friend std::ostream& operator<<(std::ostream& os, const Node& someNode); //Output overloading
};
#endif
