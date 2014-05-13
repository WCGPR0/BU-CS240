#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>
class LinkedList {
	private:
		typedef Node* NodePointer;
		NodePointer firstNode; //!<Pointer to the first node on the list
		int nodeSize; //!<Size of the list of nodes
	public:
		//! Constructor
		LinkedList();
		//! Deconstructor
		~LinkedList();
		//! Predicate method to validate if empty
		bool empty() const;
		//! Inserts an Element to front of the list
		//! @param e an Element type to be inserted
		void insertFront(Element e);
		//! Inserts an Element to the back of the list
		//! @param e an Element type to be inserted
		void insertBack(Element e);
		//! Removes the first Element
		//! @return e an Element type to be removed
		Element removeFront();
		//! Removes the last Node
		//! @return e an Element type of the removed Node
		Element removeBack();	
		//! Inserts an Element into the list given an index
		//! @param e an Element type
		//! @param i an integer representing the index, 0 inclusive
		void insertAt(Element e, int i);
		//! Removes an Element from the list given an index
		//! @param i an integer representing the index, 0 inclusive
		Element removeAt(int i);
		//! Finds an Element from the list
		//! @param e an Element type to be found
		//! @return i integer position of the element found
		int find(Element e) const;
		

		friend std::ostream& operator<<(std::ostream& os, const LinkedList& someList);

};
#endif
