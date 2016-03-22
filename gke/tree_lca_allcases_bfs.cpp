
#include<vector>
#include<iostream>


using namespace std;





struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

bool find_lca_util(struct Node *root, int n1, vector<int> *path);


Node * newNode(int k)
{
    Node *temp = new Node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}



int find_lca(struct Node *root, int n1, int n2)
{

	if(root == NULL)
	{
		return -1;
	}


	std::vector<int> path1;
	std::vector<int> path2;

	bool n1_found = false;
	bool n2_found = false;


	n1_found = find_lca_util(root, n1, &path1);

	n2_found = find_lca_util(root, n2, &path2);

	if(!n1_found || !n2_found)
	{
		return -1;
	}

	//Now compare the paths and the first differing value is the common ancestor
	for(int i = 0, j = 0; i < path1.size() || j <path2.size(); i++, j++)
	{
		if(i < path1.size() && j < path2.size())
		{
			if(path1[i] != path2[j])
			{
				return path1[i - 1];
			}
		}
		else if(i < path1.size())
		{
				return path2[j - 1];
		}	
		else if(j < path2.size())
		{
				return path1[i - 1];
			
		}
	}


	return -1;






}





bool find_lca_util(struct Node *root, int n1, vector<int> *path)
{

	if(root == NULL)
	{
		return false;
	}


	//Push current node in path

	path->push_back(root->data);


	if(root->data == n1)
	{
		return true;
	}

	bool found = find_lca_util(root->left, n1, path);
	
	if(found)
	{
		return true;
	}

	found = find_lca_util(root->right, n1, path);

	if(found)
	{
		return true;
	}

	//Not found, hence backtrack

	path->pop_back();
	
	



	return false;
	



}


// Driver program to test above functions
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << find_lca(root, 4, 5);
    cout << "\nLCA(4, 6) = " << find_lca(root, 4, 6);
    cout << "\nLCA(3, 4) = " << find_lca(root, 3, 4);
    cout << "\nLCA(2, 4) = " << find_lca(root, 2, 4);
    cout << "\nLCA(2, 10) = " << find_lca(root, 2, 10);
    cout << "\nLCA(12, 10) = " << find_lca(root, 12, 10);
    return 0;
}




