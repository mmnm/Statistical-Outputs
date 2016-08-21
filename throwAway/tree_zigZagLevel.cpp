{
#include<iostream>
#include<algorithm>
#include<stack>
	using namespace std;


	struct node
	{
		int data;
		struct node *left;
		struct node *right;
	};

	void pushInStackUtil(std::stack<struct node *> *s1, struct node *elem1, struct node *elem2);

	struct node* newNode(int data)
	{
		struct node* node = (struct node*)
		malloc(sizeof(struct node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;

		return(node);
	}

	int getTreeLevels(struct node *root)
	{
		if(root == NULL)
		{
			return 0;
		}

		int lHeight = getTreeLevels(root->left);
		int rHeight = getTreeLevels(root->right);

		return 1 + std::max(lHeight,  rHeight);

	}

	void printZigUtil(struct node *root, int level, bool printZig)
	{

		if(root == NULL)
		{
			return;
		}

		if(level == 1)
		{
			cout<<" "<<root->data;
		}

		if(printZig)
		{
			printZigUtil(root->left, level - 1, printZig);
			printZigUtil(root->right, level - 1, printZig);
		}
		else
		{
			printZigUtil(root->right, level - 1, printZig);
			printZigUtil(root->left, level - 1, printZig);
		}

	}	


	void printBTSpiral_method2(struct node *root)
	{
		if(root == NULL)
		{
			return;
		}

		std::stack<struct node *> s1;
		std::stack<struct node *> s2;

		std::stack<struct node *> *stackToUse = &s1;
		std::stack<struct node *> *stackToPush = &s2;


		s1.push(root);
		bool pushInverted = false;


		while(1)
		{

			if(stackToUse->empty())
			{
				if(stackToPush->empty())
				{
					break;
				}

				cout<<"\n";
				pushInverted = !pushInverted;
				std::stack<struct node *> *tempStack = stackToUse;
				stackToUse = stackToPush;
				stackToPush = tempStack;

			}

			struct node *cur = stackToUse->top();
			stackToUse->pop();

			cout<<" "<<cur->data;

			if(pushInverted)
			{
				pushInStackUtil(stackToPush, cur->right, cur->left);	
			}
			else
			{
				pushInStackUtil(stackToPush, cur->left, cur->right);	
			}

		}

	}


	void pushInStackUtil(std::stack<struct node *> *s1, struct node *elem1, struct node *elem2)
	{

		if(s1 == NULL)
		{
			return;
		}

		if(elem1)
		{
			s1->push(elem1);
		}

		if(elem2)
		{
			s1->push(elem2);
		}
	}






	void printBTSpiral(struct node *root)
	{
		if(root == NULL)
		{
			return;
		}


		int levels = getTreeLevels(root);

		bool printZig = true;

		for(int i = 1; i <= levels; i++)
		{
			printZigUtil(root, i, printZig);
			printZig = !printZig;
		}

	}


/* Driver program to test above functions*/
	int main()
	{
		struct node *root = newNode(1);
		root->left        = newNode(2);
		root->right       = newNode(3);
		root->left->left  = newNode(7);
		root->left->right = newNode(6);
		root->right->left  = newNode(5);
		root->right->right = newNode(4);
		printf("Spiral Order traversal of binary tree is \n");
		printBTSpiral(root);

		cout<<"\nMethod 2"<<endl;
		printBTSpiral_method2(root);
		return 0;
	}







}