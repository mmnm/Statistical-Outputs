
/* 
Given a binary tree, print all root-to-leaf paths
For the below example tree, all root-to-leaf paths are: 
10 –> 8 –> 3
10 –> 8 –> 5
10 –> 2 –> 2
*/


#include<iostream>
using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


void print_leaf_path_util(struct node *root, int *arr, int cur_i);

void print_leaf_paths(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	//Assume that tree is max 1000 elems
	int array[1000] = {0};
	//Hold current value in array
	int cur_i = 0;
		
	print_leaf_path_util(root, array, cur_i);

}

void printArr(int *arr, int max)
{
	cout<<endl;

	for(int i = 0; i <= max; i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;
}


void print_leaf_path_util(struct node *root, int *arr, int cur_i)
{
	if(root == NULL)
	{
		return;
	}
	
	arr[cur_i++] = root->data;

	//Check if leaf node
	if(!(root->left) && !(root->right))
	{
		//Path found, print it
		printArr(arr, cur_i - 1);
	}
	
	print_leaf_path_util(root->left, arr, cur_i);
	print_leaf_path_util(root->right, arr, cur_i);

}

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}
  

/* Driver program to test above functions*/
int main()
{ 
  
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  
  print_leaf_paths(root);
  
  getchar();
  return 0;
}


		




	







