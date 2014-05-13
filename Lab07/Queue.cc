template <typename T>
Queue<T>::Queue(){
}

template <typename T>
Queue<T>::~Queue(){
}

template <typename T>
bool Queue<T>::empty() {
return ll.empty();
}

template <typename T>
void Queue<T>::enqueue(T t){
if (!empty())
	ll.insert_first(t);
}

template <typename T>
T Queue<T>::dequeue() {
return	ll.delete_first();
}

template <typename T>
T Queue<T>::front() {
T tempQueue = dequeue();
enqueue(tempQueue);
return tempQueue;
}
