#include<iostream>
#include<stack>


using namespace std;


struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}


void inorder(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}






void inorder_iterative(struct Node *root)
{
	if(root == NULL)
	{
		return;
	}


	std::stack<struct Node *> s1;
	
	s1.push(root);
	struct Node *cur = root;

	while(1)
	{
		if(cur)
		{
			if(cur->left)
			{
				s1.push(cur->left);
				cur = cur->left;
			}
			else 
			{
				cur = NULL;
			}
			continue;
		}

		if(cur == NULL)
		{
			if(s1.empty())
			{
				break;
			}

			cur = s1.top();
			s1.pop();
		}
		
		
		cout<<" "<<cur->data;
		
		if(cur->right)
		{
			s1.push(cur->right);
			cur = cur->right;
			
		}
		else 
		{
			cur = NULL;
		}

	}

}




int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */

    cout<<"\nTest case 1"<<endl;
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 

    inorder_iterative(root);
    cout<<"\nTest case 1 comparision with recursive inorder: "<<endl;
    inorder(root);

    cout<<"\n************************************************";
    cout<<"\nTest case 2"<<endl;

    struct Node *root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(7);
    root1->left->left->left  = newNode(13);
    root1->left->left->left->right  = newNode(15);
    root1->left->right = newNode(6);
    root1->right->left  = newNode(5);
    root1->right->right = newNode(4);
    root1->right->right->left = newNode(20);
    root1->right->right->left->left = newNode(40);
    root1->right->right->left->left->right = newNode(60);
    root1->right->right->left->left->right->right = newNode(80);




    inorder_iterative(root1);
    cout<<"\nTest case 2 comparision with recursive inorder: "<<endl;
    inorder(root1);



    getchar();
    return 0;
  }		



