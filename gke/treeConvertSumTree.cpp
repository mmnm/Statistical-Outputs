/* 

Convert a given tree to its Sum Tree
For example, the following tree

10
/      \
-2        6
/   \      /  \ 
8     -4    7    5
should be changed to

20(4-2+12+6)
/      \
4(8-4)      12(7+5)
/   \      /  \ 
0      0    0    0


I must say the elegance of the below recursive algo is a beauty, 
it changes current state(root) and passes info to higher up (parent) */

#include<iostream>

using namespace std;


/* A tree node structure */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};


int convertSumTree(struct node *root)
{
  if(root == NULL)
  {
    return 0;
  }

  int cur_data = root->data;

  root->data = convertSumTree(root->left) + convertSumTree(root->right);

  return cur_data + root->data;

}

// A utility function to print inorder traversal of a Binary Tree
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

/* Driver function to test above functions */
int main()
{
  struct node *root = NULL;
  int x;

/* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);

  cout<<" "<<convertSumTree(root)<<endl;

// Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);

  getchar();
  return 0;
}







