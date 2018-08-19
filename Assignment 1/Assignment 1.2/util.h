#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#define and &&
#define or ||
#define xor ^
#define EXIT 0
#define INSERT 1
#define DELETE 2
#define FIND_COUSINS 3
#define FIND_SUM 4
#define PRINT_BST 5
typedef int itemType;
typedef enum{FALSE,TRUE} status;
typedef status boolean;

#define SUCCESS TRUE
#define FAILURE FALSE

typedef struct bst_node_ bstNode;
typedef bstNode* nodeData;



#endif