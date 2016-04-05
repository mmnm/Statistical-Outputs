/*
Boundary Traversal of binary tree
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. For example, boundary traversal of the following tree is “20 8 4 10 14 25 22″

*/



#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void printEdges(struct node *root, bool reverse)
{
	if(root == NULL)
	{
		return;
	}
	if(!reverse && root->left == NULL)
	{
		return;
	}
	if(reverse && root->right == NULL)
	{
		return;
	}

	if(reverse == false)
	{
		cout<<" "<<root->data;
		printEdges(root->left, reverse);
	}
	else if(reverse == true)
	{
		
		printEdges(root->right, reverse);
		cout<<" "<<root->data;
	}

}

void printLeaf(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	//Print only if leaf node
	if( !root->left && !root->right )
	{
		cout<<" "<<root->data;
	}

	printLeaf(root->left);
	printLeaf(root->right);

}
	


void printTreeBoundary(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	//Traverse from top left to bottom left and print
	//print left to right all intermediate nodes
	//Traverse bottom right to top right and print

	//Print from top to bottom left edges
	bool isReverse = false;
	printEdges(root, isReverse);
	
	//Print leaf
	printLeaf(root);
	
	//Print from bottom to top right edges
	isReverse = true;
	printEdges(root->right, isReverse);

	
}


struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
 
    printTreeBoundary(root);

    return 0;
}

