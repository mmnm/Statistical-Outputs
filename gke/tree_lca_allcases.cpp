#include<iostream>


using namespace std;



struct node
{
	int data;
	struct node *left;
	struct node *right;
};



bool find(node *root, int k)
{
    // Base Case
    if (root == NULL)
        return false;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == k || find(root->left, k) ||  find(root->right, k))
        return true;
 
    // Else return false
    return false;
}

struct node * lca_util(struct node *root, int n1, int n2, bool *n1_found, bool *n2_found)
{
	if(root == NULL)
	{
		return root;
	}

	if(root->data == n1)
	{
		*n1_found = true;
		return root;
	}
	
	if(root->data == n2)
	{
		*n2_found = true;
		return root;
	}

	struct node *left_lca = lca_util(root->left, n1, n2, n1_found, n2_found);
	struct node *right_lca = lca_util(root->right, n1, n2, n1_found, n2_found);


	
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

	return NULL;



}




struct node * lca(struct node *root, int n1, int n2)
{

	if(root == NULL)
	{
		return root;
	}

	bool n1_found = false;
	bool n2_found = false;
	
	struct node *lc = lca_util(root, n1, n2, &n1_found, &n2_found);

	if(n1_found && n2_found)
	{
		return lc;
	}
	else if(n1_found) 
	{
		if(find(lc, n2))
		{
			return lc;
		}
	}
	else if(n2_found)
	{
		if(find(lc, n1))
		{
			return lc;
		}
	}

	return NULL;

}


// Utility function to create a new tree Node
node* newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}
 


// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    node *lcaa =  lca(root, 4, 5);
    if (lcaa != NULL)
       cout << "LCA(4, 5) = " << lcaa->data;
    else
       cout << "Keys are not present ";
 
    lcaa =  lca(root, 4, 10);
    if (lcaa != NULL)
       cout << "\nlca(4, 10) = " << lcaa->data;
    else
       cout << "\nKeys are not present (4, 10)";
    
    lcaa =  lca(root, 4, 6);
    if (lcaa != NULL)
       cout << "\nlca(4, 6) = " << lcaa->data;
    else
       cout << "\nKeys are not present (4,6)";
    
    lcaa =  lca(root, 4, 2);
    if (lcaa != NULL)
       cout << "\nlca(4, 2) = " << lcaa->data;
    else
       cout << "\nKeys are not present (4,2)";
 
    return 0;
}


