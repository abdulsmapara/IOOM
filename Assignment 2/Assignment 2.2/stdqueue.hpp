#ifndef STDQUEUE_HPP_INCLUDED
#define STDQUEUE_HPP_INCLUDED
#include "stdlist_.hpp"
template <typename T>
class stdqueue
{
private:
	stdlist<T> qptr;
public:
	stdqueue();	//default constructor
	void push(const T obj);
	bool empty();
	int size();
	T front();
	void pop();
	~stdqueue();
};

#endif