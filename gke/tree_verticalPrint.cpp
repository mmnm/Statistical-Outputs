/*

Print a Binary Tree in Vertical Order | Set 1
Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
			  
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 

*/

#include<iostream>
#include<map>
#include<queue>



using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};



Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}




void printVerticalOrderUtil(struct Node *root, std::map<int, std::queue<int> > *hashQ, int level)
{

	if(root == NULL)
	{
		return;
	}

	(*hashQ)[level].push(root->data);

	
	printVerticalOrderUtil(root->left, hashQ, level - 1);
	printVerticalOrderUtil(root->right, hashQ, level + 1);


}


void printVerticalOrder(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}

	std::map<int, std::queue<int> > hashQ;
	std::map<int, std::queue<int> >::iterator  it;

	printVerticalOrderUtil(root, &hashQ, 0);


	//Now print the levels

	


	for(it = hashQ.begin(); it != hashQ.end(); it++)
	{
		
		//std::map<int, std::queue<int> > *hashP = &(it->second);

		//Print all elems in this level queue

		while(! ((it->second).empty()) )
		{
			cout<<((it->second).front())<<" ";
			((it->second).pop());
		}
		
		cout<<endl;
	}


}

// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
 
    return 0;
}


	
