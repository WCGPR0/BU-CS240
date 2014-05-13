template <typename T>
Stack<T>::Stack(){
}

template <typename T>
Stack<T>::~Stack(){
}

template <typename T>
bool Stack<T>::empty(){
return ll.empty();
}

template <typename T>
void Stack<T>::push(T t){
	ll.insert_last(t);
}

template <typename T>
T Stack<T>::pop(){
return	ll.delete_last();
}

template <typename T>
T Stack<T>::top(){
T tempStack = pop();
push(tempStack);
return tempStack;
}
