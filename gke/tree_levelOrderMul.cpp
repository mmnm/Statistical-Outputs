/*
Find multiplication of sums of data of leaves at same levels
Given a Binary Tree, return following value for it.
1) For every level, compute sum of all leaves if there are leaves at this level. Otherwise ignore it.
2) Return multiplication of all sums.

Examples:

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
#include<queue>
#include<stack>
#include<map>

using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


int productLevelSum(struct node *root)
{
	
	if(root == NULL)
	{
		return 0;
	}


	std::map<int,int> levelsSum;
	std::map<int, int>::iterator levelsSumIt;

	std::map<struct node *, int> levelInfo;
	std::map<struct node *, int>::iterator levelInfoIt;
	
	std::queue<struct node *> pQ;
	


	pQ.push(root);
	levelInfo[root] = 1;

	while(!pQ.empty())
	{
		struct node *temp = pQ.front();
		pQ.pop();
		int curLevel;
		
		levelInfoIt = levelInfo.find(temp);

		if(levelInfoIt != levelInfo.end())
		{
			//Found
			curLevel = levelInfoIt->second;
		}
		else 
		{
			cout<<"Debug this error"<<endl;
			return -1;
		}

		if((temp->left == NULL) && (temp->right == NULL))
		{
			//cout<<"Temp value is ***** "<<temp->data<<endl;
			//Leaf node, process it
			levelsSumIt = levelsSum.find(curLevel);

			if(levelsSumIt != levelsSum.end())
			{
				//Found
				levelsSum[curLevel] = levelsSum[curLevel] + 
							temp->data;
			}
			else
			{
				levelsSum[curLevel] = temp->data;
			}
		}


		if(temp->left)
		{
			levelInfo[temp->left] = curLevel + 1;
			pQ.push(temp->left);
		}

		if(temp->right)
		{
			levelInfo[temp->right] = curLevel + 1;
			pQ.push(temp->right);
		}

	}

	int retProd = 1;

	for(levelsSumIt = levelsSum.begin(); 
		levelsSumIt != levelsSum.end(); ++levelsSumIt)
	{
		//cout<<"Value is "<<levelsSumIt->second<<endl;
		retProd = retProd * levelsSumIt->second;
		//cout<<"RetProd is "<<retProd<<endl;
	}

	return retProd;
		

		

}
			
		
		

// Utility function to create a new tree node
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    node *root = newNode(2);
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
         << productLevelSum(root) << endl;
 
    return 0;
}

 

