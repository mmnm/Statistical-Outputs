/*

Construct a binary tree given its pre-order and post-order traversals

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

Remember while(start != end) versus while(start <= end)


*/








#include<iostream>


using namespace std;




struct node
{
	char data;
	struct node *left;
	struct node *right;
};




void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;	
	}

	inorder(root->left);

	cout<<" "<<root->data;
	
	inorder(root->right);

}

struct node * newNode(char data)
{
	struct node *temp = new node();
	temp->left = NULL;
	temp->right = NULL;

	temp->data = data;
	return temp;
}


int search(char *ino, char elem, int start, int end)
{
	int index = -1;
	while(start <= end)
	{
		if(ino[start] == elem)
		{
			index = start;
			break;
		}
		start++;
	}

	return index;

}


int curIndex = 0;
struct node * constructTree(char *pre, char *ino, int ino_start, int ino_end)
{
	if(curIndex == 0)
	{
		cout<<"Start and end: "<<ino_start<<" "<<ino_end<<endl;
	}

	if(ino_start > ino_end)
	{
		return NULL;
	}
	
	struct node *cur = newNode(pre[curIndex++]);

	//Now recurse for its left and right children

	int index_ino = search(ino, cur->data, ino_start, ino_end);
	
	if(index_ino == -1)
	{
		cout<<"Debug this"<<endl;
		return NULL;
	}

	
	cur->left = constructTree(pre, ino, ino_start, index_ino - 1);
	cur->right = constructTree(pre, ino, index_ino + 1, ino_end);

	return cur;



}




int main()
{

	char pre[] = {'A', 'B', 'D',  'E',  'C',  'F'};
	char ino[] = {'D', 'B', 'E', 'A', 'F', 'C'};


	struct node *root = constructTree(pre, ino, 0, sizeof(ino)/sizeof(char) - 1);


	inorder(root);


}


