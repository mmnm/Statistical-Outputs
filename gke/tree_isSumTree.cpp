

/* Is the BT tree a sum tree 

*/



#include<iostream>

using namespace std;



struct node 
{
	int data;
	struct node *left;
	struct node *right;
};



int sumOfTree(struct node *root)
{

	if (root == NULL)
	{
		return 0;
	}

	int sum = 0;

	sum += root->data;
	sum  += sumOfTree(root->left);
	sum += sumOfTree(root->right);
	
	return sum;
}


bool isSumTree(struct node *root)
{
	if(root == NULL)
	{
		return true;
	}

	
	//Check if leaf node, leaf node is always sumTree

	if( !(root->left && root->right) )
	{
		return true;
	}

	int leftsum = sumOfTree(root->left);
	int rightsum = sumOfTree(root->right);


	if( (root->data == (leftsum + rightsum)) && isSumTree(root->left) && isSumTree(root->right) )
	{
		return true;
	}

	return false;

}

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
 
    getchar();
    return 0;
}




