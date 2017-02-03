/* Print bt data by levels with each level separated by newLine



*/

#include<iostream>
#include<queue>

using namespace std;

/* Basic Algo: We can use two queues, Start with root and pjut in q1, 
process q1,
and put all child from left to right in q2, till empty. Repeat */


struct node 
{
	int data;
	struct node *left;
	struct node *right;
};




void printLevels(struct node *root)
{
	if(root == NULL)
	{
		return;
	}


	std::queue<struct node *> q1, q2;

	bool useQ2 = false;
	q1.push(root);
	
	int level = 1;

	while(!(q1.empty()) || !(q2.empty()))
	{
		struct node *curNode = NULL;
		if(useQ2)
		{
			if(q1.empty())
			{
				cout<<"\nLevel "<<level<<": ";
				level++;
				useQ2 = false;
				continue;
			} 
			else 
			{
				curNode = q1.front();
				q1.pop();

				cout<<" "<<curNode->data;
				
				if(curNode->left)
				{
					q2.push(curNode->left);
				}
				
				if(curNode->right)
				{
					q2.push(curNode->right);
				}

	
			}
		}
	
		else
		{	
			
			if(q2.empty())
			{
				cout<<"\nLevel "<<level<<": ";
				level++;
				useQ2 = true;
				continue;
			} 
			else 
			{
				curNode = q2.front();
				q2.pop();


				cout<<" "<<curNode->data;
				
				if(curNode->left)
				{
					q1.push(curNode->left);
				}
				
				if(curNode->right)
				{
					q1.push(curNode->right);
				}


			}
			
		}
	}

}


		

struct node* newNode(int data)
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
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevels(root);
 
    return 0;
}
	
	


	







