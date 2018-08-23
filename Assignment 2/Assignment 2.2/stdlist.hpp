#ifndef STDLIST_HPP_INCLUDED
#define STDLIST_HPP_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>

template <typename T>
class stdlist
{
private:
	struct list_node
	{
		T obj;
		struct list_node* next;
		list_node()
		{
			next=NULL;
		}
	};
	list_node* head,*tail;
	int count;
public:
	stdlist();
	void push_back(const T obj);
	T front();
	bool empty();
	int size();
	void pop_front();
	~stdlist();
	
};

#endif