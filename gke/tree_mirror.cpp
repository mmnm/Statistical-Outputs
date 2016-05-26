

/* Check if two trees are Mirror */


#include<iostream>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{
	int data;
	Node* left, *right;
};


bool areMirror_method2(struct Node *root1, struct Node *root2)
{

	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if( (root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) )
	{
		return false;
	}

	return areMirror_method2(root1->left, root2->right) && areMirror_method2(root1->right, root2->left) && (root1->data == root2->data);

}

bool areMirror_method3(struct Node *root1, struct Node *root2)
{
//This method does inorder and reverse inorder of these trees, if they differ then they are not mirror


	if( (root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL) )
	{
		return false;	
	}

	if(root1 == NULL)
	{
		return true;
	}

	if(areMirror_method3(root1->left, root2->right) == false)
	{
		return false;
	}

	if(root1->data != root2->data)
	{
		return false;
	}

	if(areMirror_method3(root1->right, root2->left) == false)
	{
		return false;
	}
	else 
	{
		return true;
	}

}


int areMirror_method1(Node* a, Node* b)
{
/* Base case : Both empty */
	if (a==NULL && b==NULL)
		return true;

// If only one is empty
	if (a==NULL || b == NULL)
		return false;

/* Both non-empty, compare them recursively
Note that in recursive calls, we pass left
of one tree and right of other tree */
return  a->data == b->data &&
areMirror_method1(a->left, b->right) &&
areMirror_method1(a->right, b->left);
}

/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = new Node;
	node->data  = data;
	node->left  =  node->right  = NULL;
	return(node);
}

/* Driver program to test areMirror() */
int main()
{
	Node *a = newNode(1);
	Node *b = newNode(1);
	a->left = newNode(2);
	a->right = newNode(3);
	a->left->left  = newNode(4);
	a->left->right = newNode(5);

	b->left = newNode(3);
	b->right = newNode(2);
	b->right->left = newNode(5);
	b->right->right = newNode(4);

	areMirror_method1(a, b)? cout << "Yes" : cout << "No";
	cout<<endl;
	areMirror_method2(a, b)? cout << "Yes" : cout << "No";
	cout<<endl;
	areMirror_method3(a, b)? cout << "Yes" : cout << "No";
	cout<<endl;

	return 0;
}





