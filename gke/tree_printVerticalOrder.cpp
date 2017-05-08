#include<iostream>
#include<vector>
#include<map>


using namespace std;


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node* newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printVector(std::vector<int> v)
{
	std::vector<int>::iterator iv;

	for(iv = v.begin(); iv != v.end(); iv++)
	{
		cout<<" "<<*iv;
	}
	cout<<endl;
}

void voUtil(struct node *root, int hd, std::map<int, std::vector<int> > &vhash)
{
	std::map<int, std::vector<int> >::iterator it;

	if(root == NULL)
	{
		return;
	}
	
	it = vhash.find(hd);
	
	if(it == vhash.end())
	{
		std::vector<int> v;
		v.push_back(root->data);
		vhash[hd] = v;
	}
	else 
	{
		std::vector<int> v = vhash[hd];
		v.push_back(root->data);
		vhash[hd] = v;
	}

	voUtil(root->left, hd - 1, vhash);
	voUtil(root->right, hd + 1, vhash);

}


void print_vertical(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	std::map<int, std::vector<int> > vhash;
	std::map<int, std::vector<int> >::iterator it;
	
	voUtil(root, 0, vhash);

	for(it = vhash.begin(); it != vhash.end(); it++)
	{
		printVector(it->second);
	}
}




int main()
{
    // Create binary tree shown in above figure
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);
 
    cout << "Vertical order traversal is \n";
    print_vertical(root);
 
    return 0;
}	




