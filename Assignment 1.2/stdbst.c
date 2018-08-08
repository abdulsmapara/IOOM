#include "stdbst.h"
#include "queue.h"
/*
	The structure of binary search tree node on which the whole implementation depends
*/
typedef struct bst_node_{
	itemType data;
	bstNode* left,*right;
}bstNode;


bstNode* initializeBST(bstNode* root){
	root=NULL;
	return root;
}
bstNode* makeNode(itemType data)
{
	/*
		A function to create a bst node
	*/
	bstNode* new_node=(bstNode*)malloc(sizeof(bstNode));
	if(new_node != NULL)
	{
		new_node->data=data;
		new_node->left=new_node->right=NULL;
	}

	return new_node;
}

bstNode* insertNode(bstNode* root,bstNode* element)
{
	/*
		Iterative function to insert an element in BST
	*/
	bstNode* temproot=root;
	boolean done=FALSE;
	if(element != NULL)
	{
		if(root == NULL)
		{
			root = element;
		}
		else
		{
			while(!done)
			{
				if(temproot->data < element->data)
				{
					if(temproot->right != NULL)
						temproot=temproot->right;
					else
					{
						done=TRUE;
						temproot->right = element;
					}
				}
				else if(temproot->data > element->data)
				{
					if(temproot->left != NULL)
						temproot=temproot->left;
					else
					{
						done=TRUE;
						temproot->left = element;
					}
				}
				else
				{
					done=TRUE;
					printf("ERROR CONDITION- NODE ALREADY EXISTS\n");
				}
			}
		}
	}
	else
	{
		printf("ERROR\n");
	}
	return root;
}

static void deleteNodeUtil(bstNode** element)
{
	bstNode* del,*q,*r,*p;
	if((*element) != NULL)
	{
		if((*element)->left == NULL)
		{
			del=*element;
			*element=(*element)->right;
			free(del);
			del=NULL;
		}
		else if((*element)->right == NULL)
		{
			del=*element;
			*element=(*element)->left;
			free(del);
			del=NULL;
		}
		else
		{
			p=NULL;
			for(q=(*element)->left;q->right != NULL;)
			{
				p=q;
				q=q->right;
			}
			if(p != NULL)
			{
				p->right = q->left;
				q->left=(*element)->left;
			}
			q->right=(*element)->right;
			del=(*element);
			*element=q;
			free(del);
			del=NULL;
		}
	}
	return;
}

bstNode* deleteNode(bstNode* root,itemType key)
{
	bstNode* temproot=root,*prev=NULL;
	while(temproot != NULL and temproot->data != key)
	{
		prev=temproot;
		if(temproot->data > key)
		{
			temproot=temproot->left;
		}
		else //temproot->data < key
		{
			temproot=temproot->right;
		}
	}
	if(temproot != NULL)
	{
		if(prev == NULL) //or temproot==root
		{
			deleteNodeUtil(&root);
		}
		else
		{
			if(prev->left == temproot)
			{
				deleteNodeUtil(&(prev->left));
			}
			else
			{
				deleteNodeUtil(&(prev->right));
			}
		}
	}
	else
	{
		printf("ERROR-ELEMENT NOT FOUND\n");
	}
	return root;
}
void printCousins(bstNode* root,itemType node_data)
{
	/*
		Given a node, print all its cousins
		Implementation idea based on level order traversal using queue data structure
	*/
	int count;
	QueueDS* queue;
	boolean done;
	boolean isCousinAvailable;
	bstNode* temproot;
	if(root == NULL or node_data == root->data)
	{
		printf("root is NULL or a non-NULL root has no cousin\n");
	}
	else
	{
		//level based traversal
		queue=InitializeQueue(queue);
		push(queue,root);
		done=FALSE;
		isCousinAvailable=FALSE;
		while(!emptyQueue(queue) and !done)
		{
			count=num_nodes(queue);
			while(count--){
				pop(queue,&temproot);
				//donot check root but check its children
				if((temproot->left != NULL and temproot->left->data == node_data) or (temproot->right != NULL and temproot->right->data == node_data) )
				{
					done=TRUE;
				}
				else
				{
					if(temproot->left != NULL)
					{
						push(queue,temproot->left);
					}
					if(temproot->right != NULL)
					{
						push(queue,temproot->right);
					}
				}
			}
			
		}
		if(done){
			isCousinAvailable=FALSE;
			while(!emptyQueue(queue))
			{
				isCousinAvailable=TRUE;
				pop(queue,&temproot);
				printf("%d ",temproot->data);
			}
			if(!isCousinAvailable)
				printf("NO COUSIN AVAILABLE\n");
		}
		else
		{
			printf("NODE NOT FOUND\n");
		}

	}
	return;
}
void traverse(bstNode* root){

	if(root != NULL)
	{
		traverse(root->left);
		printf("%d ",root->data);
		traverse(root->right);
	}

	return;

}

int sum_at_max_level(bstNode* root)
{
	//idea is level order traversal using queue
	int sum=0;
	bstNode* temproot;
	QueueDS* queue;
	boolean done=FALSE;
	if(root != NULL)
	{
		queue=InitializeQueue(queue);
		push(queue,root);
		sum=0;
		while(!done and !emptyQueue(queue))
		{
			int count=num_nodes(queue);
			if(count == 0)
			{
				done=TRUE;
			}
			else
			{
				sum=0;
				while(count--)
				{
					pop(queue,&temproot);
					sum+=temproot->data;
					if(temproot->left != NULL)
					{
						push(queue,temproot->left);
					}
					if(temproot->right != NULL)
					{
						push(queue,temproot->right);
					}
				}
			}
		}
	}
	else
	{
		printf("EMPTY TREE!\n");
	}
	return sum;	
}