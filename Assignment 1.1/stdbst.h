/*
	Interface for BST
	IOOM Assignment
*/
#ifndef STDBST_H_INCLUDED
#define STDBST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#define NAME_SIZE 20
#define GET_DATA 1
#define EXIT 0
#define INSERT 2
#define DELETE 3
#define and &&
#define or ||
#define xor ^
#define key int
typedef enum{FALSE,TRUE} status;
typedef status boolean;
typedef struct bst_node bst;

bst* initializeBST(bst* root);
bst* makeNode(char* student_name,int total_marks);
bst* insertNode(bst* root,bst* element);
bst* searchNode(bst* root,char* student_name,int total_marks);
void printData(bst* root);
void traverse(bst* root, boolean ascending);
bst* insert_by_user_scan(bst* root);
void deleteNodeUtil(bst** element);
bst* deleteNode(bst* root,char* student_name,int total_marks,boolean printErrors);
#endif