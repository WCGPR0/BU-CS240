/**
	Copyright 2014 - Jessica Hartog
	Binghamton University, Computer Science Department
	Binghamton, NY 13902
**/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Stack.h"
#include "Queue.h"

#define ITERATIONS 2000

int main(int argc, char* argv[]){
	/**
		Let's check to see what happens when we put
		some data into our Stack.
		Let's randomly choose some operations to perform
		on the stack and see what happens.
	**/

	srand(time(NULL));
	int iterations = ITERATIONS;

	Stack<float> float_stack;
	if(!float_stack.empty()){ std::cerr << "Didn't build the empty stack correctly." << std::endl;}
	
	float f;
	int push_count = 0, pop_count = 0;
	while(iterations > 0){
		int op = (int) rand();
		if(op%4 == 0){
			//empty test
			if(float_stack.empty() != (push_count == pop_count)){
				std::cerr << "Didn't pass empty test on a (likely) modified stack." << std::endl;
			}
		} else if(op%4 == 1){
			f = (float) rand();	
			float_stack.push(f);
			push_count++;
		} else if(op%4 == 2){
			if(float_stack.empty()){
				try{	
					f = float_stack.pop();
					std::cerr << "Failed to throw exception for pop on empty stack." << std::endl;
				} catch (std::out_of_range &oor){
					//Good we should have caught this
				}
			} else {
				try{
					f = float_stack.pop();
					pop_count++;
				} catch (std::out_of_range &oor){
					std::cerr << "Threw error when popping from a valid stack." << std::endl;
				}
			}
		} else {
			if(float_stack.empty()){
				try{	
					f = float_stack.top();
					std::cerr << "Failed to throw exception for pop on empty stack." << std::endl;
				} catch (std::out_of_range &oor){
					//Good we should have caught this
				}
			} else {
				try{
					f = float_stack.top();
				} catch (std::out_of_range &oor){
					std::cerr << "Threw error when getting top from a valid stack." << std::endl;
				}
			}	
		}
		iterations--;
	}

	iterations = ITERATIONS;
	Queue<char> char_queue;
	if(!char_queue.empty()){ std::cerr << "Didn't build the empty queue correctly." << std::endl;}

	int enq_count = 0, deq_count = 0;
	char c;
	while(iterations > 0){
		int op = (int) rand();
		if(op%4 == 0){
			//empty test
			if(char_queue.empty() != (enq_count == deq_count)){
				std::cerr << "Didn't pass empty test on a (likely) modified queue." << std::endl;
			}
		} else if(op%4 == 1){
			c = (char) rand();	
			char_queue.enqueue(c);
			enq_count++;
		} else if(op%4 == 2){
			if(char_queue.empty()){
				try{	
					c = char_queue.dequeue();
					std::cerr << "Failed to throw exception for dequeue on empty queue." << std::endl;
				} catch (std::out_of_range &oor){
					//Good we should have caught this
				}
			} else {
				try{
					c = char_queue.dequeue();
					deq_count++;
				} catch (std::out_of_range &oor){
					std::cerr << "Threw error when dequeueing from a valid queue." << std::endl;
				}
			}
		} else {
			if(char_queue.empty()){
				try{	
					c = char_queue.front();
					std::cerr << "Failed to throw exception for front on empty queue." << std::endl;
				} catch (std::out_of_range &oor){
					//Good we should have caught this
				}
			} else {
				try{
					c = char_queue.front();
				} catch (std::out_of_range &oor){
					std::cerr << "Threw error for front of a valid queue." << std::endl;
				}
			}	
		}
		iterations--;
	}

	return 0;
}

