/* Check if the tree is superbalanced. A superbalanced tree : A tree is 
"superbalanced" if the difference between the depths of any two leaf nodes ↴ is no greater than one.
*/




/* program to check if a tree is height-balanced or not */


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define bool int
struct node
{
	int data;
	struct node *left;
	struct node *right;
};



int isTreeSuperBalanced(struct node *root, bool *isSuper)
{
	if(root == NULL)
	{
		*isSuper = true;
		return 0;
	}

	int leftHeight = isTreeSuperBalanced(root->left, isSuper);

	if(*isSuper == false)
	{
		return 0;
	}

	int rightHeight = isTreeSuperBalanced(root->right, isSuper);

	if(*isSuper == false)
	{
		return 0;
	}

	if(abs(leftHeight - rightHeight) > 1)
	{
		*isSuper = false;
		return 0;
	}

	return 1 + max(leftHeight, rightHeight);

}




/* Returns the height of a binary tree */
int height(struct node* node);

/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
int lh; /* for height of left subtree */
int rh; /* for height of right subtree */

/* If tree is empty then return true */
	if(root == NULL)
		return 1; 

/* Get the height of left and right sub trees */
	lh = height(root->left);
	rh = height(root->right);

	if( abs(lh-rh) <= 1 &&
		isBalanced(root->left) &&
		isBalanced(root->right))
		return 1;

/* If we reach here then tree is not height-balanced */
	return 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */
int max(int a, int b)
{
	return (a >= b)? a: b;
} 

/* The function Compute the "height" of a tree. Height is the
number of nodes along the longest path from the root node
down to the farthest leaf node.*/
int height(struct node* node)
{
/* base case tree is empty */
	if(node == NULL)
		return 0;

/* If tree is not empty then height = 1 + max of left
height and right heights */
	return 1 + max(height(node->left), height(node->right));
} 

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);



	struct node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	root1->right->left = newNode(6);
	root1->right->right = newNode(7);
	root1->left->left->left = newNode(8);



/* Test case 1 */

	if(isBalanced(root))
		printf("\nTree is balanced");
	else
		printf("\nTree is not balanced"); 

/* Test case 2 */

	bool super = true;
	isTreeSuperBalanced(root, &super);


	if(super)
		printf("\nTree is balanced");
	else
		printf("\nTree is not balanced"); 



/* Test case 2 */

	if(isBalanced(root1))
		printf("\nTree is balanced");
	else
		printf("\nTree is not balanced"); 

/* Test case 2 */

	super = true;
	int height = 0;
	height = isTreeSuperBalanced(root1, &super);


	if(super)
		printf("\nTree is balanced with height: %d", height);
	else
		printf("\nTree is not balanced"); 



	getchar();
	return 0;
}




