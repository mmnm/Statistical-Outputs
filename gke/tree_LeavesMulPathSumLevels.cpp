/*
Input: Root of below tree
         2
       /   \
      7     5
             \
              9
Output: 63
First levels doesn't have leaves. Second level
has one leaf 7 and third level also has one 
leaf 9.  Therefore result is 7*9 = 63


Input: Root of below tree
         2
       /   \
     7      5
    / \      \
   8   6      9
      / \    /  \
     1  11  4    10 

Output: 208
First two levels don't have leaves. Third
level has single leaf 8. Last level has four
leaves 1, 11, 4 and 10. Therefore result is 
8 * (1 + 11 + 4 + 10)  

*/

#include<iostream>
#include<map>
#include<queue>

using namespace std;


/*
algo description:

mulSumTillNow -> 1

do level order traversal->
	for each Node
		if new level begins
			mulSumTillNow *= TempSum	 
		
		check if leaf Node 
			if yes
				add -> TempSum

	return mulSumTillNow


*/


struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};


int productLeafSum(struct Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	/* Two queues in use to keep track of each new level */
	std::queue<struct Node *> q1;
	std::queue<struct Node *> q2;
	std::queue<struct Node *> *qInUse = &q1;
	std::queue<struct Node *> *qToPush = &q2;


	int prodTotal = 1;
	int sumLeafLevel = -1; 
	bool useQ1 = true;

	q1.push(root);

	while(!qInUse->empty())
	{
		struct Node *temp = qInUse->front();
		qInUse->pop();

		if(temp == NULL)
		{
			cout<<"Debug this error"<<endl;
		}

		//Check if this Node is leaf Node and addToSum 
		if( !temp->left && !temp->right )
		{
			if(sumLeafLevel == -1)
			{
				sumLeafLevel = temp->data;
			}
			else
			{
				sumLeafLevel += temp->data;
			}
		}

		//Prepare the queue for next iteration
		if(temp->left)
		{
			qToPush->push(temp->left);
		}	
		if(temp->right)
		{
			qToPush->push(temp->right);
		}	
		
				

		//This suggests end of current Level
		if(qInUse->empty())
		{
			if( !(sumLeafLevel == -1) )
			{
				prodTotal *= sumLeafLevel;
			}


			//Reset the queue usage and sumLeafLevel
			sumLeafLevel = -1;

			if(useQ1)
			{
				qInUse = &q2;
				qToPush = &q1;
				useQ1 = false;
			}
			else
			{
				qInUse = &q1;
				qToPush = &q2;
				useQ1 = true;
			}
				
			
		}

	}

	return prodTotal;

}


// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    Node *root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(10);
 
    cout << "Final product value = "
         << productLeafSum(root) << endl;
 
    return 0;
}
			

















