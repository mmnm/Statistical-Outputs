/*

Symmetric Tree (Mirror Image of itself)
Given a binary tree, check whether it is a mirror of itself.

For example, this binary tree is symmetric:

1
/   \
2     2
/ \   / \
3   4 4   3
But the following is not:

1
/ \
2   2
\   \
3    3


*/

/* 


method 1 : do inorder and reverseIno at the same time and if they differ return false; else true at the end
method 2:  check if left and right are mirrors and cur->left->data = cur->right->data; return true else return false

*/

#include<iostream>
using namespace std;

// A Binary Tree Node
struct node
{
	int data;
	struct node* left, *right;
};

// Utility function to create new Node
node *newNode(int key)
{
	node *temp = new node();
	temp->data  = key;
	temp->left  = temp->right = NULL;
	return (temp);
}



bool isMirrorInoUtil(struct node *root1, struct node *root2)
{

	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	else if(root1 == NULL || root2 == NULL)
	{
		return false;
	}


	if(isMirrorInoUtil(root1->left, root2->right) == false) 
	{
		return false;
	}

	if(root1->data != root2->data)
	{
		return false;
	}

	if(isMirrorInoUtil(root1->right, root2->left) == false) 
	{
		return false;
	}

	return true;


}



bool isMirror_method1(struct node *root)
{
	if(root == NULL)
	{
		return true;
	}


	return isMirrorInoUtil(root, root);


}

bool isMirror_method2(struct node *root1, struct node *root2)
{

	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	else if(!root1 || !root2)
	{
		return false;
	}

	if(isMirror_method2(root1->left, root2->right) && isMirror_method2(root1->right, root2->left) && (root1->data == root2->data))
	{
		return true;
	}

	return false;


}	







// Driver program
int main()
{
// Let us construct the Tree shown in the above figure
	node *root        = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(2);
	root->left->left  = newNode(3);
	root->left->right = newNode(4);
	root->right->left  = newNode(4);
	root->right->right = newNode(3);

	cout << isMirror_method1(root)<<endl;
	cout << isMirror_method2(root, root)<<endl;

	node *root1        = newNode(1);
	root1->left        = newNode(2);
	root1->right       = newNode(4);
	root1->left->left  = newNode(3);
	root1->left->right = newNode(4);
	root1->right->left  = newNode(4);
	root1->right->right = newNode(3);

	cout << isMirror_method1(root1)<<endl;
	cout << isMirror_method2(root1, root1)<<endl;
	return 0;
}








