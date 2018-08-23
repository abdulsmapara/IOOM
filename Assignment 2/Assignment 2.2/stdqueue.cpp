#include "stdqueue.hpp"

template <typename T>
stdqueue<T>::stdqueue(){
}
template <typename T>
void stdqueue<T>::push(const T obj)
{
	try{
	qptr.push_back(obj);
	}catch(const char* msg){
		throw msg;
	}
}
template <typename T>
bool stdqueue<T>::empty()
{
	return qptr.empty();
}
template <typename T>
T stdqueue<T>::front()
{
	return qptr.front();
}
template <typename T>
void stdqueue<T>::pop()
{
	try{
	qptr.pop_front();
	}catch(const char* msg){
		throw msg;
	}
}
template <typename T>
int stdqueue<T>::size(){
	return qptr.size();
}
template <typename T>
stdqueue<T>::~stdqueue(){
/*no need to write explicitly*/
}