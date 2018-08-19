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
	gcc -o a marks.c stdbst.c
	a.exe (windows)
*/

#include "stdbst.h"
int main(){
	/*
		DRIVER CODE
	*/

	/*<var declarations>*/
	int num_of_students,i,choice,undo,total_marks;
	bst* root;
	char student_name[NAME_SIZE];
	boolean exit_status;
	/*</var declarations>*/

	/*<initialize>*/
	student_name[0]='\0';
	total_marks=0;
	choice=-1;
	root=initializeBST(root);
	exit_status=FALSE;
	undo=0;
	/*</initialize>*/

	root=insert_by_user_scan(root);


	/*provide options to user*/
	printf("MENU\n1. GET DATA WITH MARKS IN ASCENDING ORDER\n2. INSERT DATA FOR A FEW MORE STUDENTS \n3. DELETE DATA OF A STUDENT\n0. EXIT\n");
	while(!exit_status)
	{
		printf("ENTER A CHOICE\n");
		while(!(scanf("%d",&choice) == 1 and choice >=0 and choice <= 3))
		{
			printf("ENTER A VALID CHOICE\n");
		}
		switch(choice)
		{
			case GET_DATA:
						traverse(root,TRUE);
						break;
			case INSERT:
						root=insert_by_user_scan(root);
						break;
			case DELETE:
						printf("ENTER THE NAME OF THE STUDENT\n");
						while(!(scanf("%s",student_name) == 1 and strlen(student_name) < NAME_SIZE ))
						{
							printf("PLEASE ENTER A VALID NAME\t");
						}
						printf("ENTER AGGREGATE MARKS OF %s\t",student_name);
						while(!(scanf("%d",&total_marks) == 1))
						{
							printf("PLEASE ENTER A VALID VALUE\n");
						}
						root=deleteNode(root,student_name,total_marks,TRUE);
						break;
			case EXIT:
						exit_status=TRUE;
						printf("THANK YOU\n");
						break;
			default:
						printf("PLEASE ENTER A VALID CHOICE\n");
		}
	}


	return 0;
}
