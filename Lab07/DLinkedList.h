#ifndef DLINKEDLIST
#define DLINKEDLIST

#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>
template <typename Element>
class DLinkedList {
	private:
		typedef Node<Element>* NodePointer;
		NodePointer firstNode; //!<Pointer to the first node on the list
		NodePointer lastNode;
		int nodeSize; //!<Size of the list of nodes
	public:
		//! Constructor
		DLinkedList();
		//! Deconstructor
		~DLinkedList();
		//! Predicate method to validate if empty
		bool empty() const;
		//! Inserts an Element to front of the list
		//! @param e an Element type to be inserted
		void insert_first(Element e);
		//! Inserts an Element to the back of the list
		//! @param e an Element type to be inserted
		void insert_last(Element e);
		//! Removes the first Element
		//! @return e an Element type to be removed
		Element delete_first();
		//! Removes the last Node
		//! @return e an Element type of the removed Node
		Element delete_last();	
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
		//! Delete all elements of specified value
		//! @return i integer count of deleted Elements
		int delete_value(Element e);
		//! Gets the amount total Elements
		//! @return i integer of Elements
		int count() const;

		friend std::ostream& operator<<(std::ostream& os, const DLinkedList<Element>& someList);

};

#include "Stack.cc"
#endif
