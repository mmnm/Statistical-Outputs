#include<iostream>

using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};






 
struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}



 int tree_sum(struct node *root)
 {
     if(root == NULL)
     {
         return 0;
     }
     
     int leftSum = tree_sum(root->left);
     int rightSum = tree_sum(root->right);
     return root->data + leftSum + rightSum;
     
 }
 
 void convertBSTUtil(struct node *root, int *prev)
 {
     if(root == NULL)
     {
         return;
     }
     convertBSTUtil(root->left, prev);
     *prev -= root->data;
     root->data = *prev;
     convertBSTUtil(root->right, prev);

 }
struct node* convertBST(struct node* root) {
    
    if(root == NULL)
    {
        return NULL;
    }
    
    int prevSum = tree_sum(root);
    convertBSTUtil(root, &prevSum);
    return root;
}

void printInorder(struct node *root)
{
    if (root == NULL) return;
 
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


// Driver Program to test above functions
int main()
{
    struct node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
 
    convertBST(root);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    printInorder(root);
 
    return 0;
}
