#include<iostream>
#include<climits>

using namespace std;

struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};



/* 

left <= middle < right

*/
void isBSTUtil(struct Node *root, int *prev, bool *status)
{
	if(root == NULL)
	{
		return;
	}

	isBSTUtil(root->left, prev, status);

	//Perform the BST check
	if(*prev > root->data)
	{
		*status = false;
		return;
	}
	else
	{
		*prev = root->data;
	}	
		
	isBSTUtil(root->right, prev, status);


}



bool isBST(struct Node *root)
{

	bool status = true;
	
	if(root == NULL)
	{
		return status;
	}

	int prev = INT_MIN;
	
	isBSTUtil(root, &prev, &status);
	return status;

}


struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
 
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}
