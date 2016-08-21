
#include<iostream>
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

int getTreeLevels(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int lHeight = getTreeLevels(root->left);
	int rHeight = getTreeLevels(root->right);

	return 1 + std::max(lHeight,  rHeight);

}

void printZigUtil(struct node *root, int level, bool printZig)
{

	if(root == NULL)
	{
		return;
	}

	if(level == 1)
	{
		cout<<" "<<root->data;
	}

	if(printZig)
	{
		printZigUtil(root->left, level - 1, printZig);
		printZigUtil(root->right, level - 1, printZig);
	}
	else
	{
		printZigUtil(root->right, level - 1, printZig);
		printZigUtil(root->left, level - 1, printZig);
	}

}	




void printBTSpiral(struct node *root)
{
	if(root == NULL)
	{
		return;
	}


	int levels = getTreeLevels(root);

	bool printZig = true;

	for(int i = 1; i <= levels; i++)
	{
		printZigUtil(root, i, printZig);
		printZig = !printZig;
	}

}


/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(7);
	root->left->right = newNode(6);
	root->right->left  = newNode(5);
	root->right->right = newNode(4);
	printf("Spiral Order traversal of binary tree is \n");
	printBTSpiral(root);

	return 0;
}







