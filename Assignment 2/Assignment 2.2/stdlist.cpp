#include "stdlist.hpp"
template <typename T>
stdlist<T>::stdlist()
{
	head=tail=NULL;
	count=0;
}
template <typename T>
bool stdlist<T>::empty()
{
	return (head==NULL and tail==NULL);
}

template <typename T>
void stdlist<T>::push_back(const T obj)
{
	list_node* ptr=new list_node;
	if(ptr == NULL)
	{
		throw "Insufficient Memory";
	}
	else
	{
		ptr->obj = obj;
		if(this->empty())
		{
			head=tail=ptr;
		}
		else
		{
			tail->next = ptr;
			tail=ptr;
		}
		count++;
	}
}
template <typename T>
T stdlist<T>::front()
{
	if(this->empty())
	{
		throw "Empty List";
	}
	else
	{
		return head->obj;
	}
}
template <typename T>
int stdlist<T>::size()
{
	return count;
}
template <typename T>
void stdlist<T>::pop_front()
{
	if(this->empty())
	{
		throw "Empty List";
	}
	else
	{
		stdlist::list_node* del=NULL;
		del=head;
		head=head->next;
		delete del;
		if(head == NULL)
		{
			tail=NULL;
		}
		count--;
	}
}
template <typename T>
stdlist<T>::~stdlist(){
	list_node* ptr=head;
	list_node* del=NULL;
	while(ptr != NULL)
	{
		del=ptr;
		ptr=ptr->next;
		delete del;
	}
	cout << "Memory Released" <<endl;
}