#include "stdbst.h"
/*
	VNIT, NAGPUR
	DT. 02nd AUGUST,2018
	IOOM(Introduction to Object Oriented Methodology) 5th semester
	Lab Assignment 1
	R3 Batch
	GUIDED BY 	- M. Dhabu Ma'am
		   		  CSE,VNIT, Nagpur
	SUBMITTED BY- Abdul Sattar Mapara
				  R3 BATCH
				  BT16CSE053
				  abdulsmapara.github.io
*/
//gcc -o a linkedlist.c queue.c stdbst.c main.c; a.exe < test or a.exe for custom i/p
int main()
{
	//Driver code
	printf("IOOM\nMENU-BST PROBLEM 2\n1. INSERT ELEMENTS\n2. DELETE ELEMENTS\n3. PRINT COUSINS TO GIVEN NODE\n4. FIND SUM AT MAXIMUM LEVEL(LAST LEVEL)\n5. TRAVERSE BST 0. EXIT\n");
	int choice;
	bstNode* root;
	itemType data;
	int num_nodes;
	root=initializeBST(root);
	do
	{
		printf("ENTER A CHOICE\n");
		while(!(scanf("%d",&choice) == 1 and choice <= 5 and choice >= 0))
		{
			printf("ENTER A VALID CHOICE\n");

		}
		switch(choice)
		{
			case INSERT:
						printf("ENTER THE NUMBER OF NODES\n");
						while(! (scanf("%d",&num_nodes) == 1 and num_nodes >= 0))
						{
							printf("ENTER A VALID NUMBER\n");
						}
						while(num_nodes--)
						{
							printf("ENTER THE DATA IN THE FORM OF INTEGER\n");
							while(scanf("%d",&data)!=1)
								printf("ENTER VALID DATA\n");
							root=insertNode(root,makeNode(data));
						}
						break;
			case DELETE:
						printf("ENTER DATA VALUE TO BE DELETED\n");
						while(scanf("%d",&data) != 1)
						{
							printf("ENTER VALID DATA\n");
						}
						root=deleteNode(root,data);
						break;
			case FIND_COUSINS:
						printf("ENTER DATA VALUE\n");
						while(scanf("%d",&data) != 1)
						{
							printf("ENTER VALID DATA\n");
						}
						printCousins(root,data);
						break;
			case FIND_SUM:
						printf("ANS=%d\n",sum_at_max_level(root));
						break;
			case PRINT_BST:
						traverse(root);
						break;
			case EXIT:
						printf("THANK YOU\n");
						break;
			default:
						printf("INVALID CHOICE\n");
						break;
		}
	}while(choice != EXIT);

	return 0;
}
