#include<iostream>

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

void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}  


void mirror(struct node *root)
{

	//pre
	if(root == NULL)
	{
		return;
	}

	struct node *temp = root->left;
	root->left = root->right;
	root->right = temp;


	mirror(root->left);
	mirror(root->right);





}







/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
   
  /* Convert tree to its mirror */
  mirror(root); 
   
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  inOrder(root);
   
  getchar();
  return 0;  
}

