/* 

Calculate max path sum 

Input: Root of below tree
       1
      / \
     2   3
Output: 6

1+2+3


*/



#include<iostream>
#include<algorithm>


using namespace std;



struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};


int maxPathSum(struct Node *root, int *maxSum)
{
	if(root == NULL)
	{
		return 0;
	}

	int lSum = maxPathSum(root->left, maxSum);
	int rSum = maxPathSum(root->right, maxSum);


	if(lSum  < 0)
	{
		lSum = 0;
	}

	if(rSum < 0)
	{
		rSum = 0;
	}
	

	int rootSum = root->data + lSum + rSum;



	if(*maxSum < rootSum)
	{
		*maxSum = rootSum;
	}
	
	rootSum = max(lSum, rSum) + root->data;

	return rootSum;	 
		

}

 
 
// A utility function to allocate a new Node
struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return (newNode);
}


// Driver program
int main(void)
{
	struct Node *root = newNode(10);
	root->left	 = newNode(2);
	root->right	 = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(4);
	int maxSum = 0;
	cout << "Max path sum is "<<endl;
	maxPathSum(root, &maxSum);

	cout<<" "<<maxSum<<endl;
	maxSum = 0;
	return 0;
}


