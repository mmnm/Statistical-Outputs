/*
Find Count of Single Valued Subtrees
Given a binary tree, write a program to count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. Expected time complexity is O(n).

Example:

Input: root of below tree
              5
             / \
            1   5
           / \   \
          5   5   5
Output: 4
There are 4 subtrees with single values.


Input: root of below tree
              5
             / \
            4   5
           / \   \
          4   4   5                
Output: 5
There are five subtrees with single values.

*/







#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

bool singleValTree(struct node *root, int *count)
{
	if(root == NULL)
		return true;

	bool isLeftSin = singleValTree(root->left, count);
	bool isRightSin = singleValTree(root->right, count);

	
	if(isLeftSin && isRightSin )
	{
		if(root->left && root->right)
		{
			if( (root->data == root->left->data) &&
			    (root->data == root->right->data) )
			{
				*count = *count + 1;
				return true;
			}
			else 
			{
				return false;
			}
		}
		else if(root->left && !root->right) 
		{
			if(root->left->data == root->data)
			{
				*count = *count + 1;
				return true;
			}
		}
		else if(!root->left && root->right) 
		{
			if(root->right->data == root->data)
			{
				*count = *count + 1;
				return true;
			}
		}
		else if(!root->left && !root->right)
		{
			*count = *count + 1;
			return true;
		}
		else 
		{
			cout<<"Debug this"<<endl;
		}
	}

	
	return false;

}



struct node * newNode(int val)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
	 

// Driver program to test
int main()
{
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);
 
	int count = 0;
         singleValTree(root, &count);

    cout << "Count of Single Valued Subtrees is " <<count<<endl;
    return 0;
}		
