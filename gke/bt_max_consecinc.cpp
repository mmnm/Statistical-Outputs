/* 

Given a Binary Tree find the length of the longest path which comprises of Nodes with consecutive dataues in increasing order. Every Node is considered as a path of length 1.


       10
      /    \     
     /      \
    11        9	
   / \        /\
  /   \      /  \
13    12    13   8
Maximum Consecutive Path Length is 3 (10, 11, 12)
Note: 10, 9 ,8 is NOT considered since
the Nodes should be in increasing order.

	    5
          /  \
         /    \
        8      11
        /        \
       /          \
       9	  10   
      /	          /
     /	         /
    6           15
Maximum Consecutive Path Length is 2 (8, 9).


*/

#include<iostream>
using namespace std;


struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

void max_consec_util(struct Node *root, int *max, int curLen, int prevVal);

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 

int max_consec(struct Node *root)
{
	if(root == NULL) 
	{
		return 0;
	}

	int curLen = -1;
	int maxLen = 0;

	max_consec_util(root, &maxLen, curLen, -1);

	return maxLen;

}


void max_consec_util(struct Node *root, int *max, int curLen, int prevVal)
{

	if(root == NULL) 
	{
		return;
	}

	if( (prevVal == -1) || ((root->data - prevVal) != 1) )
	{
		curLen = 1;
	}
	else 
	{
		curLen++;
	}

	if(*max < curLen) 
	{
		*max = curLen;
	}

	
	max_consec_util(root->left, max, curLen, root->data);
	max_consec_util(root->right, max, curLen, root->data);

	
}





//Driver program to test above function
int main()
{
    Node *root = newNode(10);
    root->left = newNode(11);
    root->right = newNode(9);
    root->left->left = newNode(13);
    root->left->right = newNode(12);
    root->right->left = newNode(13);
    root->right->right = newNode(8);
 
    cout << "Maximum Consecutive Increasing Path Length is "
         << max_consec(root)<<endl;
 
    return 0;
}

	


















