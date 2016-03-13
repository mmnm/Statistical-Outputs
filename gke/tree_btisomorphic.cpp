#include<iostream>


using namespace std;



struct node 
{

	int data;
	struct node *left;
	struct node *right;

};




bool isIsomorphic(struct node *root1, struct node *root2)
{
	
	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	else if(root1 == NULL)
	{
		return false;
	}
	else if(root2 == NULL)
	{
		return false;
	}

	
	if( (root1->data == root2->data) && 
		( (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) || 
		  (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left)) ) )
	{
		return true;
	}
	

	return false;
}



node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
 
/* Driver program to test above functions*/
int main()
{
    // Let us create trees shown in above diagram
    struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
 
    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
 
    if (isIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
 
    return 0;
}





		
