#ifndef STDBST_HPP_INCLUDED
#define STDBST_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*======CONSTANTS=====*/
#define INSERT 1
#define DELETE 2
#define TRAVERSE 3
#define EXIT 0
const int NAME_SIZE=20;
/*======/CONSTANTS=====*/

/*class  definition of stdbst*/
class stdbst
{
private:
	//Structure for Tree Node
	struct node
	{
		char student_name[NAME_SIZE];
		int total_marks;
		struct node *left,*right;
		node()
		{
			student_name[0]='\0';
			total_marks=0;
			left=right=NULL;
		}
	};
	/*private methods to support public methods*/
	void traverse_util(const stdbst::node* root);
	void deleteNodeUtil(stdbst::node** root);
	void delete_complete(stdbst::node* root);

	/*Root of the tree*/
	node* root;
public:
	stdbst();	//Default Constructor
	void insert_in_bst(const char* student_name,const int total_marks);
	void traverse();
	void delete_from_bst(const char* student_name,const int total_marks,const bool printErrors);
	~stdbst();
};

#endif