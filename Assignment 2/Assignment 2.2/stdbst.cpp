#include "stdbst.hpp"
#include "stdqueue_.hpp"
stdbst::stdbst()
{
	this->root=NULL;
}
void stdbst::insert_in_bst(const char* student_name,const int total_marks)
{
	//check for exception
	if(student_name == NULL or strlen(student_name) > NAME_SIZE or total_marks < 0)
	{
		throw "Invalid Data Provided";
	}
	else
	{
		node* element = new node;	//To be added
		node* temp_root=this->root;	//Root stored
		if(element != NULL)
		{
			strcpy(element->student_name,student_name);
			element->total_marks = total_marks;
			element->left=element->right=NULL;		//for safety but not required
			//now insert in bst
			if(this->root == NULL)
			{
				this->root = element;
			}
			else
			{
				bool done=false,error=false;
				while(!done and !error)
				{
					if(strcmp(temp_root->student_name,element->student_name) == 0)
					{
						/*
							UPDATION MAY CREATE A PROBLEM HERE.
							AVOID UPDATE AND RAISE AN ERROR
						*/
						error=true;
						throw "ERROR CONDITION..THE STUDENT ALREADY EXISTS...UPDATE NOT ALLOWED\n";
					}
					else if(temp_root->total_marks < element->total_marks)
					{
						if(temp_root->right != NULL)
							temp_root=temp_root->right;
						else
						{
							done=true;
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
							done=true;
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
								done=true;
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
								done=true;
								temp_root->right=element;
							}
						}
					}
				}
			}
		}
		else
		{
			throw "Insufficient Memory";
		}
	}
}
void stdbst::traverse_util(const stdbst::node* root)
{
	if(root != NULL)
	{
		traverse_util(root->left);
		cout<<root->student_name<<" "<<root->total_marks<<endl;
		traverse_util(root->right);
	}
	return;
}
void stdbst::traverse()
{
	traverse_util(root);
	return;
}
void stdbst::deleteNodeUtil(stdbst::node** element)
{
	node* del=NULL,*p,*q;
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
			delete del;
			del=NULL;
		}
		else if((*element)->right == NULL)
		{
			del=*element;
			*element=(*element)->left;
			delete del;
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
			delete del;
			del=NULL;
		}
	}
	return;
}
void stdbst::delete_from_bst(const char* student_name,const int total_marks,const bool printErrors)
{
	node* temp_root,*prev;
	bool found=false;
	temp_root=root;
	prev=NULL;
	while(temp_root != NULL and !found)
	{
		if(strcmp(temp_root->student_name,student_name)==0 and temp_root->total_marks == total_marks)
		{
			found=true;
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
			throw "Not Found Exception";
		}
	}
	return;
}
void stdbst::find_cousin(const char* student_name,const int total_marks)
{
	if(student_name == NULL or strlen(student_name) > NAME_SIZE or total_marks < 0)
	{
		throw "No cousin possible for such data\n";
	}
	else
	{
		node* bst_root=this->root;
		node* temproot;
		int count;
		bool done,isCousinAvailable;
		stdqueue<node*> q;
		if(bst_root == NULL or (bst_root->total_marks == total_marks and strcmp(bst_root->student_name,student_name)==0))
		{
			throw "No cousin found\n";
		}
		else
		{
			q.push(bst_root);
			done=isCousinAvailable=false;
			while(!q.empty() and !done)
			{
				count = q.size();
				while(count--)
				{
					temproot = q.front();
					q.pop();
					if((temproot->left != NULL and (temproot->left->total_marks == total_marks and strcmp(temproot->left->student_name,student_name)==0)) or (temproot->right != NULL and (temproot->right->total_marks == total_marks and strcmp(temproot->right->student_name,student_name)==0)))
					{
						done=true;
					}
					else
					{
						if(temproot->left != NULL)
						{
							q.push(temproot->left);
						}
						if(temproot->right != NULL)
						{
							q.push(temproot->right);
						}
					}
				}

			}
			if(done){
				isCousinAvailable=false;
				while(!q.empty())
				{
					isCousinAvailable=true;
					temproot=q.front();
					q.pop();
					cout<<temproot->student_name<<" "<<temproot->total_marks<<endl;
				}
				if(!isCousinAvailable)
					throw "NO COUSIN AVAILABLE\n";
			}
			else
			{
				throw "NODE NOT FOUND\n";
			}
		}
	}
}
int stdbst::max_level_sum()
{
	//idea is level order traversal using queue
	int sum=0;
	node* temproot;
	stdqueue<node*> q;
	bool done=false;
	if(this->root != NULL)
	{
		q.push(root);
		sum=0;
		while(!done and !q.empty())
		{
			int count=q.size();
			if(count == 0)
			{
				done=true;
			}
			else
			{
				sum=0;
				while(count--)
				{
					temproot=q.front();
					q.pop();
					sum += temproot->total_marks;
					if(temproot->left != NULL)
					{
						q.push(temproot->left);
					}
					if(temproot->right != NULL)
					{
						q.push(temproot->right);
					}
				}
			}
		}
	}
	else
	{
		throw "Empty Tree";
	}
	return sum;	
}
void stdbst::delete_complete(stdbst::node* root)
{
	if(root != NULL)
	{
		try{
			delete_complete(root->left);
			delete_complete(root->right);
			
			delete_from_bst(root->student_name,root->total_marks,false);
			
		}catch(const char* msg){
			//donot print here
		}
	}
}
stdbst::~stdbst(){
	delete_complete(root);
	cout << "Complete memory released" <<endl;
}