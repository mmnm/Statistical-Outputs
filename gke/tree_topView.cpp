/*

      1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6


*/





#include<iostream>
#include<queue>
#include<map>

using namespace std;

void printTopViewUtil(struct Node *root, 
			std::map<int, struct Node *> &topView);

struct Node 
{
	int key;
	struct Node *left;
	struct Node *right;
};



void printTopView(struct Node *root)
{
	if(root == NULL)
		return;

	
	std::map<int, struct Node *> topView;
	printTopViewUtil(root, topView);

	std::map<int, struct Node *>::iterator it; 

	for(it = topView.begin(); it != topView.end(); it++)
	{
		cout<<" "<<it->second->key;
	}

	
}
	

void printTopViewUtil(struct Node *root, 
			std::map<int, struct Node *> &topView)
{
	if(root == NULL)
		return;

	int hHeight = 0;

	std::map<struct Node *, int> hHeightHash;
	std::map<int, struct Node *>::iterator it;


	//We need to do level order to maintain the property of the 
	//top elems in view if there are more elems in one hHeight


	std::queue<struct Node *> q1;

	q1.push(root);
	hHeightHash[root] = 0;
	

	while(!q1.empty())
	{
		struct Node *cur = q1.front();
		q1.pop();

		//Derive hHeight
		hHeight = hHeightHash[cur];

		
		it = topView.find(hHeight);

		if(it != topView.end())
		{
			//Found, and we dont need to update anything for now

		}
		else 
		{
			topView[hHeight] = cur;
		}
	
		//Prepare for its children

		if(cur->left)
		{
			hHeightHash[cur->left] = hHeight - 1;
			q1.push(cur->left);
		}

		if(cur->right)
		{
			hHeightHash[cur->right] = hHeight + 1;
			q1.push(cur->right);
		}
	}


}

Node* newNode(int key)
{
	struct Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;

}


// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    printTopView(root);

   /*Another test case

	       1
    /     \
   2       3
  /  \    / \
 4    5  6   7

   */
  
    Node * root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    cout<<endl;
    printTopView(root1);

    return 0;
}

	

			
