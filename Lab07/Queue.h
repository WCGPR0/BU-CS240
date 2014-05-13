/**
	Copyright 2014 - Jessica Hartog
	Binghamton University, Computer Science Department
	Binghamton, NY 13902
**/
#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdexcept>
#include "DLinkedList.h"

template <typename T>
class Queue{
	public:
		Queue();
		~Queue();
		bool empty();
		void enqueue(T t);
		T dequeue();
		T front();
	private:
		DLinkedList<T> ll;
};

#include "Queue.cc"

#endif //__QUEUE_H_
