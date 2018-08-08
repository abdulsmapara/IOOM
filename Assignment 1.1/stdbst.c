/*
	Implementation of BST-IMPROVED VERSION
	Corresponding header file stdbst.h
*/
#include "stdbst.h"
typedef struct bst_node{
	char student_name[NAME_SIZE];
	key total_marks;
	bst* left,*right;
}bst;
bst* initializeBST(bst* root)
{
	root=NULL;
	return root;
}

bst* makeNode(char* student_name,int total_marks)
{
	bst* new_node=NULL;
	if(student_name != NULL)
	{
		int len=strlen(student_name);
		if(len > 0 and len < NAME_SIZE)
		{
			new_node=(bst*)malloc(sizeof(bst));
			if(new_node != NULL)
			{
				strcpy(new_node->student_name,student_name);
				new_node->total_marks=total_marks;
				new_node->left=new_node->right=NULL;
			}
		}
	}
	return new_node;
}
bst* insertNode(bst* root,bst* element)
{
	if(element != NULL)
	{
		if(root == NULL)
		{
			root=element;
		}
		else
		{
			bst* temp_root=root;
			status done=FALSE;
			status error=FALSE;
			while(!done and !error)
			{
				if(strcmp(temp_root->student_name,element->student_name) == 0)
				{
					/*
						UPDATION MAY CREATE A PROBLEM HERE.
						AVOID UPDATE AND RAISE AN ERROR
					*/
					error=TRUE;
					printf("ERROR CONDITION..THE STUDENT ALREADY EXISTS...UPDATE NOT ALLOWED\n");
				}
				else if(temp_root->total_marks < element->total_marks)
				{
					if(temp_root->right != NULL)
						temp_root=temp_root->right;
					else
					{
						done=TRUE;
						temp_root->right=element;
					}
				}
				else if(temp_root->total_marks > element->total_marks)
				{
					if(temp_root->left != NULL)
					{
						temp_root=temp_root->left;
					}
					else
					{
						done=TRUE;
						temp_root->left=element;
					}
				}
				else //if(temp->root->total_marks == element->total_marks)
				{
					//comparision by names now
					if(strcmp(temp_root->student_name,element->student_name) > 0)
					{
						if(temp_root->left != NULL)
						{
							temp_root=temp_root->left;
						}
						else
						{
							done=TRUE;
							temp_root->left=element;
						}
					}
					else
					{
						if(temp_root->right != NULL)
						{
							temp_root=temp_root->right;
						}
						else
						{
							done=TRUE;
							temp_root->right=element;
						}
					}
				}
			}

		}
	}
	return root;
}
bst* searchNode(bst* root,char* student_name,int total_marks)
{
	bst* search_result=NULL;
	bst* temp_root=root;
	while(search_result==NULL and temp_root != NULL)
	{
		if(strcmp(temp_root->student_name,student_name)==0 and temp_root->total_marks==total_marks)
		{
			search_result=temp_root;
		}
		else if(temp_root->total_marks > total_marks)
		{
			temp_root = temp_root->left;
		}
		else if(temp_root->total_marks < total_marks)
		{
			temp_root = temp_root->right;
		}
		else //marks are same
		{
			if(strcmp(temp_root->student_name,student_name) > 0)
			{
				temp_root = temp_root->left;
			}
			else
			{
				temp_root = temp_root->right;				
			}
		}
	}
	return search_result;
}
inline void printData(bst* root)
{
	if(root != NULL)
	{
		printf("NAME- %s  MARKS = %d\n",root->student_name,root->total_marks);
	}
	return;
}
void traverse(bst* root,boolean ascending)
{
	if(root != NULL)
	{
		if(ascending)
		{
			traverse(root->left,ascending);
			printData(root);
			traverse(root->right,ascending);
		}
		else
		{
			traverse(root->right,FALSE);
			printData(root);
			traverse(root->left,FALSE);
		}
	}
	return;
}
bst* insert_by_user_scan(bst* root)
{
	char student_name[NAME_SIZE];
	int total_marks,i,num_of_students;

	student_name[0]='\0';
	total_marks=0;
	/*start initial scan from user <scan_initial>*/
	printf("ENTER NUMBER OF STUDENTS\t");
	while(!(scanf("%d",&num_of_students) == 1 and num_of_students > 0))
	{
		printf("PLEASE ENTER A VALID VALUE\n");
	}
	printf("ENTER THE DATA OF EACH STUDENT\n");
	for(i=0;i<num_of_students;i++)
	{
		printf("ENTER NAME OF THE STUDENT\t");
		while(!(scanf("%s",student_name) == 1 and strlen(student_name) < NAME_SIZE ))
		{
			printf("PLEASE ENTER A VALID NAME\t");
		}
		printf("ENTER AGGREGATE MARKS OF %s\t",student_name);
		while(!(scanf("%d",&total_marks) == 1))
		{
			printf("PLEASE ENTER A VALID VALUE\n");
		}
		root=insertNode(root,makeNode(student_name,total_marks));
		student_name[0]='\0';
	}
	/*done with initial scan </scan_initial>*/
	return root;
}
void deleteNodeUtil(bst** element)
{
	bst* del=NULL,*p,*q;
	p=q=NULL;
	/*
		If value is in leaf, then delete the node and set parent's appropriate child pointer to NULL
		Or 
		If single child is present then delete the node ans set parent's child = its child
		Or
		Go to the left(or right) and the to the rightmost node(or leftmost node) pluck it and place it in place of deleted node
	*/
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
			for(q = (*element)->left , p = NULL ; q->right != NULL;)
			{
				p=q;
				q=q->right;
			}
			if(p != NULL)
			{
				p->right = q->left;
				q->left=(*element)->left;				
			}
			q->right = (*element)->right;
			del=(*element);
			*element = q;
			free(del);
			del=NULL;
		}
	}
	return;
}
bst* deleteNode(bst* root,char* student_name,int total_marks,boolean printErrors)
{
	bst* temp_root,*prev;
	boolean found=FALSE;
	temp_root=root;
	prev=NULL;
	while(temp_root != NULL and !found)
	{
		if(strcmp(temp_root->student_name,student_name)==0 and temp_root->total_marks == total_marks)
		{
			found=TRUE;
		}
		else if(temp_root->total_marks < total_marks)
		{
			prev=temp_root;
			temp_root=temp_root->right;
		}
		else if(temp_root->total_marks > total_marks)
		{
			prev=temp_root;
			temp_root=temp_root->left;
		}
		else //marks are same
		{
			if(strcmp(temp_root->student_name,student_name) > 0)
			{
				prev = temp_root;
				temp_root = temp_root->left;
			}
			else
			{
				prev = temp_root;
				temp_root = temp_root->right;
			}
		}
	}
	if(found)
	{
		if(temp_root == root)
		{
			deleteNodeUtil(&root);
		}
		else
		{
			if(prev->left == temp_root)
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
		if(printErrors)
		{
			printf("NOT FOUND\n");
		}
	}
	return root;
}