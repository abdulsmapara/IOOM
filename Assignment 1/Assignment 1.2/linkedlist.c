#include "linkedlist.h"

typedef struct NodeTag {

	nodeData data;
	Node* next;
	
}Node;

Node* MakeNode(nodeData data)
{
	Node* new_node=(Node*)malloc(sizeof(Node));
	if(new_node != NULL)
	{
		new_node->data=data;
		new_node->next=NULL;
	}
	return new_node;
}
void push_back(Node** head,Node** tail,Node* element)
{
	if(*head == NULL ) //and *tail==NULL
	{
		*head=*tail=element;
		(*head)->next=NULL;
		(*tail)->next=NULL;
	}
	else
	{
		(*tail)->next=element;
		*tail=element;
		(*tail)->next=NULL;//safety
	}
	return;
}
nodeData pop_front(Node** head,Node** tail)
{
	nodeData data=NULL;
	if(*head != NULL){
		data=(*head)->data;
		Node* del=*head;
		*head=(*head)->next;
		if(*head == NULL)
			*tail=NULL;
		free(del);
		del=NULL;
	}
	return data;
}