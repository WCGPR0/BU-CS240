/**
	Copyright 2014 - Jessica Hartog
	Binghamton University, Computer Science Department
	Binghamton, NY 13902
**/
#ifndef __STACK_H_
#define __STACK_H_

#include <stdexcept>
#include "DLinkedList.h"

template <typename T>
class Stack{
	public:
		Stack();
		~Stack();
		bool empty();
		void push(T t);
		T pop();
		T top();
	private:
		DLinkedList<T> ll;
};

#include "Stack.cc"

#endif //__STACK_H_
