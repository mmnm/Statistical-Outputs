#include<iostream>
#include<algorithm>


using namespace std;


struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

/* 
	Algo:
	for every max sum thru a Node, it can be max of these

	root-data
	root-data + root-leftsum
	root-data + root-rightsum
	root-data + root-leftsum + root-rightsum

	Debug:

	1. Remember what you are returning from a function as a calculation
		result. In this example, we return single_sum rather that 
		max_sum seen on this node
	

*/

struct Node* newNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}


int max_path_sum_util(struct Node *root, int *max_seen)
{
	if(root == NULL)
	{
		return 0;
	}

	int leftSum = max_path_sum_util(root->left, max_seen);
	int rightSum = max_path_sum_util(root->right, max_seen);

	int totalsum = root->data + leftSum + rightSum;
	int max_single = max(max(leftSum, rightSum) + root->data, root->data);

	totalsum = max(max_single, totalsum);	

	
	if(*max_seen < totalsum)
	{
		*max_seen = totalsum;
	}
	
	return max_single;

}
	


int max_path_sum(struct Node *root)
{
	int max_seen = 0;

	if(root == NULL)
	{
		return 0;
	}
	max_path_sum_util(root, &max_seen);
	
	return max_seen;
}


// Driver program
int main(void)
{
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    cout << "Max path sum is " << max_path_sum(root);
    return 0;
}












