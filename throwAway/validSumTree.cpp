/*

Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

26
/   \
10     3
/    \     \
4      6      3


*/


#include<iostream>
using namespace std;


struct node
{
	int data;
	struct node* left;
	struct node* right;
};

bool isLeaf(struct node *root)
{
	if(!root->left && !root->right)
	{
		return true;
	}
	else 
	{
		return false;
	}

}

int assignSum(struct node *root)
{

	int sum = 0;

	if(root == NULL)
	{
		return sum;
	}

	if(isLeaf(root))
	{
		sum = root->data;
	}
	else
	{
		sum = 2 * root->data;
	}

	return sum;
}




bool isValidSumTree(struct node *root)
{

	if(root == NULL)
	{
		return true;

	}

	if(isLeaf(root))
	{
		return true;	
	}

	int leftSum = 0;
	int rightSum = 0;

	leftSum = assignSum(root->left);
	rightSum = assignSum(root->right);

	if(root->data == leftSum + rightSum)
	{
		return true;
	}

	return false;
}


struct node* newNode(int data)
{
	struct node* node =
	(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}


/* Driver program to test above function */
int main()
{
	struct node *root  = newNode(26);
	root->left         = newNode(10);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(6);
	root->right->right = newNode(3);
	if(isValidSumTree(root))
		printf("The given tree is a SumTree ");
	else
		printf("The given tree is not a SumTree ");

	getchar();
	return 0;
}














