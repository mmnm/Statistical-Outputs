
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




/*think about it what is your solution, if we start from root and check left is equal right, then it is symmetric tree otherwise not
recurse step
if left tree is symmetric to right , then symmetric otherwise not

//Do preorder on left and right and if not equal then not mirror 

*/

#include<iostream>

using namespace std;
bool checkMirrorIter1Util(struct Node *node1, struct Node *node2);
void isMirrorUtil(struct Node *node1, struct Node *node2, bool *status);

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}


bool checkMirrorIter1(struct Node *root)
{
	if(root == NULL)
		return true;

	//Do two preorders
	
	bool status = checkMirrorIter1Util(root->left, root->right);

	return status;
}

bool checkMirrorIter1Util(struct Node *node1, struct Node *node2)
{
	if(!node1 && !node2)
		return true;

	if((!node1 && node2) || (node1 && !node2))
		return false;

	if(node1->key != node2->key)
		return false;

	bool status = false;
	
	status = checkMirrorIter1Util(node1->left, node2->right);
	if(!status)
		return status;

	status = checkMirrorIter1Util(node1->right, node2->left);

	return status;

}
	
bool isMirror(struct Node *root)
{
	if(root == NULL)
		return false;


	bool status = true;
	
	isMirrorUtil(root, root, &status);
	return status;
}

void isMirrorUtil(struct Node *node1, struct Node *node2, bool *status)
{
	if(node1 == NULL && node2 == NULL)
		return;

	if((!node1 && node2) || (node1 && !node2))
	{	*status = false;
		return;
	}
	
	isMirrorUtil(node1->left, node2->right, status);

	if(node1->key != node2->key)
	{
		*status = false;
		return;
	}

	isMirrorUtil(node1->right, node2->left, status);

}

// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root        = newNode(9);
    root->left        = newNode(2);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);
 
    cout << checkMirrorIter1(root);
	
    cout << isMirror(root);
    return 0;
}
	


