/* Calculate the diameter of a binary tree */


#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;



struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


struct node* newNode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int getHeight(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int leftH = getHeight(root->left);
	int rightH = getHeight(root->right);

	return 1 + std::max(leftH, rightH);

}


int diameter(struct node *root) 
{
	if(root == NULL)
	{
		return 0;
	}

	int leftD = diameter(root->left);
	int rightD = diameter(root->right);
	leftD = max(leftD, rightD);

	int rootD = getHeight(root->left) + getHeight(root->right) + 1;

	return std::max(leftD, rootD);

}

int diameter_optimized(struct node *root, int *height)
{
	if(root == NULL)
	{
		*height = 0;
		return 0;
	}



	int lHeight = 0;
	int rHeight = 0;

	int leftD = diameter_optimized(root->left, &lHeight);
	int rightD = diameter_optimized(root->right, &rHeight);	
	int rootD = 1 + lHeight + rHeight;

	leftD = max(leftD, rightD);

	*height = 1 + max(lHeight, rHeight);

	return max(leftD, rootD);

}

int main()
{

/* Constructed binary tree is 
1
/   \
2      3
/  \
4     5
*/
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	int height = 0; 
	printf("Diameter of the given binary tree is %d\n", diameter(root));
	printf("Diameter of the given binary tree is %d\n", diameter_optimized(root, &height));

	getchar();
	return 0;
}


























