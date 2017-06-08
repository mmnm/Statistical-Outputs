#include<iostream>
#include<queue>
#include<stack>


using namespace std;


struct node
{       
        int data;       
        struct node *left;
        struct node *right;
};


void printLevel(struct node *root) 
{
	if(root == NULL)
	{
		return;
	}

	std::queue<struct node *> q1, q2;
	std::queue<struct node *> *qToUse = &q1, *qToPush = &q2;
	bool useQ1 = true;

	q1.push(root);

	int count = 0;
	cout<<"\nLevel "<<++count<<":";

	while(!(qToUse->empty()))
	{
	
		struct node *cur = qToUse->front();
		qToUse->pop();
	
		cout<<" "<<cur->data;

		if(cur->left) 
		{
			qToPush->push(cur->left);
		}

		if(cur->right)
		{
			qToPush->push(cur->right);
		}

		if(qToUse->empty())
		{
		
			cout<<"\nLevel "<<++count<<":";
			
			if(useQ1) 
			{
				qToUse = &q2;
				qToPush = &q1;
	
			}
			else
			{
				qToUse = &q1;	
				qToPush = &q2;
			}

			useQ1 = !useQ1;
		}

	}

}



void printZigZag(struct node *root) 
{
	if(root == NULL)
	{
		return;
	}

	std::queue<struct node *> q1, q2;
	std::stack<struct node *> s1;

	std::queue<struct node *> *qToUse = &q1, *qToPush = &q2;
	bool useQ1 = true;
	bool useS1 = true;

	q1.push(root);
	s1.push(root);

	int count = 0;
	cout<<"\nLevel "<<++count<<":";

	while(!(qToUse->empty()))
	{
	
		struct node *cur = qToUse->front();
		qToUse->pop();
	
		if(useS1) 
		{
			struct node *curS = s1.top();
			s1.pop();
			cout<<" "<<curS->data;
		} 
		else 
		{
			cout<<" "<<cur->data;
		}


		if(cur->left) 
		{
			qToPush->push(cur->left);
			if(!useS1)
			{
				s1.push(cur->left);
			}
		}

		if(cur->right)
		{
			qToPush->push(cur->right);
			if(!useS1)
			{
				s1.push(cur->right);
			}
		}

		if(qToUse->empty())
		{
		
			cout<<"\nLevel "<<++count<<":";
			
			useS1 = !useS1;
			
			if(useQ1) 
			{
				qToUse = &q2;
				qToPush = &q1;
	
			}
			else
			{
				qToUse = &q1;	
				qToPush = &q2;
			}

			useQ1 = !useQ1;
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
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->right  = newNode(10);
    root->right->left->right  = newNode(11);
    root->right->right->left = newNode(12);
    root->left->left->right->left  = newNode(13);
    root->left->left->right->right  = newNode(14);
    root->left->right->right->right  = newNode(15);
    root->left->left->right->left->right  = newNode(16);
    root->left->right->right->right->left  = newNode(17);
    
    printf("Level Order traversal of binary tree is \n");
    printLevel(root);

    printf("\n\nZig Zag Level Order traversal of binary tree is \n");
    printZigZag(root);
    return 0;
}
