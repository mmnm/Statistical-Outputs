#include<iostream>


using namespace std;



struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};



// Helper function to allocates a new Node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void findTreeDensityUtil(struct Node *root, int level, float *count, int *height)
{
	if(root == NULL)
	{
		return;
	}


	if(*height < level) 
	{
		*height = level;
	}

	*count = *count + 1;
	
	findTreeDensityUtil(root->left, level + 1, count, height);
	findTreeDensityUtil(root->right, level + 1, count, height);
}

	

float findTreeDensity(struct Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	float count = 0.0;
	int max_height = 0;

	findTreeDensityUtil(root, 1, &count, &max_height);

	return (count / max_height);


}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	printf("Density of given binary tree is %f",
		findTreeDensity(root));

	return 0;
}


	

	
