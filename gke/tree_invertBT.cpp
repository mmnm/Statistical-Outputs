/*

Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4


Algo: 
visit node
assign left node as right node 
assign right node as left node

visit left node
visit right node


1

3  2


*/

#include<iostream>
using namespace std;


struct node
{
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node* Node;
typedef struct node node;
 
void inorder(Node root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
Node newNode(int data) {
     
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return(temp);
}

struct node * invert_bt(struct node *root)
{
  if(root == NULL)
  {
    return NULL;
  }

  struct node *temp = root->left;
  root->left = root->right;
  root->right = temp;


  invert_bt(root->left);
  invert_bt(root->right);

  return root;
}


int main() {
 
// Let us construct the BST shown in the below figure
    Node root         = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \    / \
     4    5  6  7
   
  */
   
    root = invert_bt(root);
    inorder(root);
    return 0;
}












