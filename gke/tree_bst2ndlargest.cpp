/* Find the 2nd largest elem in BST
Handle all edge cases */






#include<iostream>



using namespace std;



struct node 
{
	int data;
	struct node *left;
	struct node *right;
};







struct node * find_rightmost(struct node *root, struct node **parent)
{

	while(root->right != NULL)
	{
		*parent = root;
		root = root->right;
	}

	return root;

		

}




void print_secondLargest(struct node *root)
{
	if(root == NULL || ( !(root->left) && !(root->right)) )
	{
		return;
	}

	


	//If the root doesnt have right child, then the left child is the 2nd largest 

	if(root->right == NULL)
	{
		cout<<root->data<<endl;
	}
		

	struct node *parent_largest = NULL;

	struct node *rightmost = find_rightmost(root, &parent_largest);

	if(rightmost->left)
	{
		//Find the rightmost of this
		struct node *temp = find_rightmost(rightmost->left, &parent_largest);

		if(temp != NULL)
		{
			cout<<temp->data<<endl;
		}
	}
	else 
	{
		if(parent_largest != NULL)
		{
			cout<<parent_largest->data<<endl;
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
 
    printf("2nd largest is \n");
    print_secondLargest(root);



    //Test case 2

	

    struct node *root1 = newNode(65);
    root1->left        = newNode(50);
    root1->right       = newNode(70);
    root1->left->left  = newNode(40);
    root1->left->right = newNode(60);
  

    root1->right->left = newNode(67);
    root1->right->right = newNode(80);
    root1->right->right->left = newNode(75);
    root1->right->right->right = newNode(150);
    root1->right->right->right->left = newNode(130);
    root1->right->right->right->left->left = newNode(110);
    root1->right->right->right->left->right = newNode(145);
    root1->right->right->right->left->right->left = newNode(140);



    printf("2nd largest is \n");
    print_secondLargest(root1);
	



	






 
    return 0;
}




