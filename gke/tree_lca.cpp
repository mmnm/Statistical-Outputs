/* LCA in BT */
/* Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of Nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor
*/



#include<iostream>

using namespace std;


struct Node 
{
	int key;
	struct Node *left;
	struct Node *right;
};


struct Node * findLCA(struct Node *root, int val1, int val2) 
{
	if(root == NULL)
		return root;


	if( (root->key ==val1) || (root->key == val2))
		return root;

	struct Node *findLCA_left = findLCA(root->left, val1, val2);
	struct Node *findLCA_right = findLCA(root->right, val1, val2);

	if(findLCA_left && findLCA_right)
	{
		return root;
	}
	else if(findLCA_left && !findLCA_right)
	{
		return findLCA_left;
	}
	else if(!findLCA_left && findLCA_right)
	{
		return findLCA_right;
	}
	else 
	{
		return NULL;
	}


}

Node* newNode(int key)
{
	struct Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;

}


// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
    return 0;
}
