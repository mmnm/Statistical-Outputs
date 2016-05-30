
/* Find the tree lca for all cases
The cases being if n1 or n2 is NULL then return NULL;

*/

#include<iostream>

using namespace std;




struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

};


Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


struct Node * find_lcaUtil(struct Node *root, int n1, int n2, bool *n1Found, bool *n2Found)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data == n1)
	{
//Found n1
		*n1Found = true;
		return root;
	}

	if(root->data == n2)
	{
//Found n2
		*n2Found = true;
		return root;
	}


	struct Node *left_lca = find_lcaUtil(root->left, n1, n2, n1Found, n2Found);
	struct Node *right_lca = find_lcaUtil(root->right, n1, n2, n1Found, n2Found);

	if(left_lca && right_lca)
	{
		return root;
	}
	else if(left_lca)
	{
		return left_lca;
	}
	else if(right_lca)
	{
		return right_lca;
	}
	else
	{
		return NULL;
	}

}	


bool searchMe(struct Node *root, int data)
{
	if(root == NULL)
	{
		return false;
	}

	if(root->data == data)
	{
		return true;
	}

	if(searchMe(root->left, data) == true)
	{
		return true;
	}

	if(searchMe(root->right, data) == true)
	{
		return true;
	}

	return false;

}






struct Node * find_lca(struct Node *root, int n1, int n2)
{
	if(root == NULL)
	{
		return NULL;
	}

	bool isN1Found = false;
	bool isN2Found = false;


	struct Node *lca = find_lcaUtil(root, n1, n2, &isN1Found, &isN2Found);


	if(isN1Found && isN2Found)
	{
		return lca;
	}
	else if(isN1Found)
	{
		if(searchMe(root, n2))
		{
			return lca;
		}
		else
		{
			return NULL;
		}
	}
	else if(isN2Found)
	{
		if(searchMe(root, n2))
		{
			return lca;
		}
		else
		{
			return lca;
		}
	}

	return NULL;


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

	Node *lca =  find_lca(root, 4, 5);

	if (lca != NULL)
		cout << "LCA(4, 5) = " << lca->data;
	else
		cout << "Keys are not present ";

	lca =  find_lca(root, 4, 10);

	if (lca != NULL)
		cout << "\nLCA(4, 10) = " << lca->data;
	else
		cout << "\nKeys are not present\n ";


	cout << "LCA(4, 5) = " << find_lca(root, 4, 5)->data;
	cout << "\nLCA(4, 6) = " << find_lca(root, 4, 6)->data;
	cout << "\nLCA(3, 4) = " << find_lca(root, 3, 4)->data;
	cout << "\nLCA(2, 4) = " << find_lca(root, 2, 4)->data;

	return 0;
}










