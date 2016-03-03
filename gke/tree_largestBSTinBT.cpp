/* Find the largest BST in a given BT - Return the size of largest BT */


//Algo is Find the length of longest increasing subsequence in a in-order traversal. The size of the BST will be lcs - 1


#include<iostream>
using namespace std;



struct node 
{
	int data;
	struct node *left;
	struct node *right;
};





void longestBSTinBTUtil(struct node *root, int *max_len_seen, int *cur_len, int *prevValue)
{

	if(root == NULL)
	{
		return;
	}

	longestBSTinBTUtil(root->left, max_len_seen, cur_len, prevValue);

	//Process the current node
	if(*prevValue < root->data)
	{
		*cur_len += 1;
	}
	else
	{
		*cur_len = 1;
	}
	if(*max_len_seen < *cur_len)
	{
		*max_len_seen = *cur_len;
	}
	
	*prevValue = root->data;

	longestBSTinBTUtil(root->right, max_len_seen, cur_len, prevValue);


}


int longestBSTinBT(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	

	int max_len_seen = 0;
	int cur_len = 0;
	int  prevValue = -1;


	longestBSTinBTUtil(root, &max_len_seen, &cur_len, &prevValue);

	//Discuss this 	
	return max_len_seen;
}


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
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
 45     65    80
  */
  printf(" Size of the largest BST is %d", longestBSTinBT(root));
 
  return 0;
}
