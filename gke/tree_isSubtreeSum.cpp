/* 

Subtree with given sum in a Binary Tree
You are given a binary tree and a given sum. The task is to check if there exist a subtree whose sum of all nodes is equal to the given sum.



*/


#include<iostream>
#include<map>

using namespace std;




struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node* newnode(int data)
{
	struct node* n = new node;
	n->data = data;
	n->left = n->right  = NULL;
	return (n);
}



int isSubTreeSum(struct node *root, int sum, bool *isSumTree)
{
	if(root == NULL)
	{
		return 0;
	}



	int leftSum = isSubTreeSum(root->left, sum, isSumTree);

	if( (*isSumTree == true) || (leftSum + root->data == sum) )
	{	
		*isSumTree = true;
		return 0;
	}

	int rightSum = isSubTreeSum(root->right, sum, isSumTree);

	if( (*isSumTree == true) || (rightSum + root->data == sum) )
	{	
		*isSumTree = true;
		return 0;
	}


	if(rightSum + leftSum + root->data == sum)
	{
		*isSumTree = true;
	}

	return leftSum + rightSum + root->data;
}


// driver program to run the case
int main()
{
	struct node *root = newnode(8);
	root->left    = newnode(5);
	root->right   = newnode(4);
	root->left->left = newnode(9);
	root->left->right = newnode(7);
	root->left->right->left = newnode(1);
	root->left->right->right = newnode(12);
	root->left->right->right->right = newnode(2);
	root->right->right = newnode(11);
	root->right->right->left = newnode(3);
	int sum = 22;

	bool status = false;
	isSubTreeSum(root, sum, &status);

	if(status)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}	








