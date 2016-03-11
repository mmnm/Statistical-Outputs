#include<iostream>


using namespace std;


//Distinct unique values only


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



void isBSTUtil(struct node *root, bool *status, int *prev)
{


	if(root == NULL)
	{
		return;
	}


	isBSTUtil(root->left, status, prev);
	
	//Compare prev with cur
	if(*prev != -1)
	{
		if(*prev >=` root->data)
		{
			*status = false;
			return;
		}
	}
        
	//Update prev
	*prev = root->data;


	isBSTUtil(root->right, status, prev);


			
}



bool isBST(struct node *root)
{

	if(root == NULL)
	{
		return true;
	}


	bool status = true;
	int prev = -1;

	isBSTUtil(root, &status, &prev);

	return status;


}


/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  


