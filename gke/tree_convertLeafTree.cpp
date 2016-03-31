/* Convert the tree into sum tree 

*/



#include<iostream>
#include<algorithm>
#include<map>

using namespace std;


struct node 
{

	int data;
	struct node *left;
	struct node *right;
};

int getHeight(struct node *root)
{

	if(root == NULL)
	{
		return 0;
	}

	int lheight = getHeight(root->left);
	int rheight = getHeight(root->right);

	return 1 + max(lheight, rheight);

}



void convertToSumTreeUtil(struct node *root, int level, std::map<struct node *, int> &hash)
{
	if(root == NULL)
	{
		return;
	}

	std::map<struct node *, int>::iterator it;

	if(level == 1)
	{
		//cout<<"Processing for " <<root->data<<endl;
		//Push the current root value to the hashMap
		//If leaf node then make root->data = 0
		//update root->data with the left and right sum values 
		
		hash[root] = root->data;
		

		if( !(root->left) && !(root->right) ) 
		{
			//Leaf node
			root->data = 0;
		}
		else 
		{
		
			int sum = 0;
			
			it = hash.find(root->left);
			if( it != hash.end() )
			{
				//Found
				//cout<<"Found pair for " <<it->second<<endl;
				sum += it->second;
				hash.erase(it);
			}
		
			it = hash.find(root->right);
			if( it != hash.end() )
			{
				//Found
				//cout<<"Found pair for " <<it->second<<endl;
				sum += it->second;
				hash.erase(it);
			}
			root->data = 0;
			if(root->left)
			{
				root->data = root->left->data;
			}
			if(root->right)
			{
				root->data = root->data + root->right->data;
			}


			root->data += sum;
		}
	} 
	else 
	{
		convertToSumTreeUtil(root->left, level - 1, hash);
		convertToSumTreeUtil(root->right, level - 1, hash);
	}


}	



void convertToSumTree(struct node *root)
{

	if(root == NULL)
	{
		return;
	}


	if( !(root->left && root->right) )
	{
		root->data = 0;
		return;
	}


	int height = getHeight(root);

	//Now traverse each node in reverse Level order and convert it to sumTree

	std::map<struct node *, int> nodeHash;


	for(int i = height; i >= 1; i--)
	{

		convertToSumTreeUtil(root, i, nodeHash);
	}

	/*
	cout<<"Contents of hash"<<endl;

	std::map<struct node *, int>::iterator it;

	for(it = nodeHash.begin(); it != nodeHash.end(); it++)
	{
		cout<<"Node / Value "<<it->first<<" " <<it->second<<endl;
	}
	*/


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
 
 convertToSumTree(root);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
 
  getchar();
  return 0;
}	
