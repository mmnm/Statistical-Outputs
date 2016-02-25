/*

Print Levels with newLine
*/


#include<iostream>
#include<map>
#include<queue>




using namespace std;




struct node
{
	int data;
	struct node *left;
	struct node *right;
};



void printLevelElems(struct node *root)
{
	if(root == NULL)
		return;


	std::queue<struct node *> q1;
	std::queue<struct node *> q2;

	std::queue<struct node *> *qToUse = &q1;
	std::queue<struct node *> *qToPush = &q2;
	bool useQ1 = true;


	qToUse->push(root);

	while(!qToUse->empty())
	{
		struct node *temp = qToUse->front();
		qToUse->pop();
		
		if(temp == NULL)
		{
			cout<<"Something not right"<<endl;
			return;
		}

		cout<<" "<<temp->data;
		
		if(temp->left)
		{
			qToPush->push(temp->left);
		}

		if(temp->right)
		{
			qToPush->push(temp->right);
		}
		

		
		if(qToUse->empty())
		{
			if(useQ1)
			{
				qToUse = &q2;
				qToPush = &q1;
				useQ1 = false;
			}
			else
			{
				qToUse = &q1;
				qToPush = &q2;
				useQ1 = true;
					
			}
			cout<<endl;
	
		}
	}


}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
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
    printLevelElems(root);
 
    return 0;
}







		
	



