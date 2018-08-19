#include "queue.h"

typedef struct queueds{
	Node* front,*rear;
	int count;
}QueueDS;

QueueDS* InitializeQueue(QueueDS* qptr)
{

	qptr=(QueueDS*)malloc(sizeof(QueueDS));
	if(qptr != NULL){
		qptr->front=qptr->rear=NULL;
		qptr->count=0;
	}
	return qptr;
}
boolean emptyQueue(QueueDS* qptr)
{
	return (qptr->front==NULL and qptr->rear==NULL);
}

boolean fullQueue(QueueDS* qptr)
{
	return FALSE;
}
status push(QueueDS* qptr,nodeData element)
{
	status sc=SUCCESS;
	Node* ptr;
	if(qptr==NULL)
	{
		sc=FAILURE;
	}
	else{
		if(fullQueue(qptr))
		{
			sc=FAILURE;
		}
		else
		{
			ptr=MakeNode(element);
			if(ptr == NULL)
			{
				sc=FAILURE;
			}
			else
			{
				push_back(&(qptr->front),&(qptr->rear),ptr);
				qptr->count+=1;
			}
		}
	}
	return sc;
}
status pop(QueueDS* qptr,nodeData* ret)
{
	status sc=SUCCESS;
	if(qptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		if(emptyQueue(qptr))
		{
			sc=FAILURE;
		}
		else
		{
			*ret=pop_front(&(qptr->front),&(qptr->rear));
			if(qptr->count > 0)
				qptr->count-=1;
		}
	}
	return sc;
}
int num_nodes(QueueDS* qptr)
{
	return qptr->count;
}


