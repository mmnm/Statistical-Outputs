/*


Input : 
in[]   = {2, 1, 3}
post[] = {2, 3, 1}

Output : Root of below tree
1
/   \
2     3 


Input : 
in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

Output : Root of below tree
1
/     \
2        3
/    \   /   \
4     5   6    7
\
8



*/



#include<iostream>

using namespace std;



struct node 
{
	int data;
	struct node *left;
	struct node *right;
};



struct node * newNode(int data)
{
	struct node *cur = new node();
	cur->data = data;
	cur->left = NULL;
	cur->right = NULL;
	return cur;
}


int searchIndex(int *ino, int data, int start, int end)
{

	int index = -1;
	if(start > end)
	{	
		return -1;
	}

	while(start <= end)
	{
		if(ino[start] == data)
		{
			index = start;
			break;
		}
		start++;
	}

	return index;
}




int curIndex = 0;

struct node * constructTreeFromInoPos(int *ino, int *post, int startIndexIno, 
	int endIndexIno)
{


	if(ino == NULL || post == NULL)
	{
		return NULL;
	}

	if(startIndexIno > endIndexIno)
	{
		return NULL;
	}

	if(curIndex < 0)
	{
		cout<<"Debug this"<<endl;
		return NULL;
	}

	int post_data = post[curIndex];
	curIndex--;
	struct node *curNode = newNode(post_data);


//Find the search index
	int ino_index = searchIndex(ino, post_data, startIndexIno, endIndexIno);


//Process the right node first


	if(ino_index == -1)
	{
		cout<<"Debug this"<<endl;
		return curNode;
	}


	curNode->right = 
	constructTreeFromInoPos(ino, post, ino_index + 1, endIndexIno);
	curNode->left = 
	constructTreeFromInoPos(ino, post, startIndexIno, ino_index - 1);

	return curNode;
}

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




int main()
{

	int ino[] =  {4, 8, 2, 5, 1, 6, 3, 7};
	int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

	curIndex = sizeof(ino)/sizeof(int) - 1;



	struct node *cur = constructTreeFromInoPos(ino, post, 0, 
		sizeof(ino)/sizeof(int) - 1);

	inorder(cur);
	return 0;

}









