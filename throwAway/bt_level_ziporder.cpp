/* 

Level order traversal zip -zap
*/


#include<iostream>
#include<queue> 
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
 


void levelorder(struct node *root)
{
	if(root == NULL) 
	{
		return;
	}


	std::queue<struct node *> q1, q2;
	std::queue<struct node *> *qToPush, *qToProcess;
	

	qToProcess = &q1;
	qToPush = &q2;
	bool useQ1 = true;
	
	q1.push(root);


	while(!(qToPush->empty()) || !(qToProcess->empty()))
	{
		struct node *cur = qToProcess->front();
		qToProcess->pop();

		cout<<" "<<cur->data;

		if(cur->left) 
		{
			qToPush->push(cur->left);
		}

		if(cur->right) 
		{
			qToPush->push(cur->right);
		}
		
		if(qToProcess->empty())
		{
			cout<<endl;
			
			if(useQ1) 
			{
				useQ1 = false;
				qToProcess = &q2;
				qToPush = &q1;
			}
			else 
			{
				useQ1 = true;
				qToProcess = &q1;
				qToPush = &q2;
			}
		}
	}

	
}	


int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n"); 
    levelorder(root); 
    return 0;
}		 



