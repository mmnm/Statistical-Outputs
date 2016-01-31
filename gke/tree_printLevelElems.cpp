/* Print level number elems in a tree */

#include<cstdlib>
#include<map>
#include<queue>
#include<iostream>
using namespace std;



/* What is my algo:
start with root and traverse in level order using queue, keep track of next level number for elems. 
Once elem level number matches the input level number print the level
Edge cases: 1 elem, no match, last level match , first level match

*/ 

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


void * printandReturnLevelTree(struct node *root, int levelNumber)
{
	if((root == NULL) ||(levelNumber < 1))
	{
		return  NULL;
	}

	std::queue<struct node *> q1;
	std::map<struct node *, int> levelInfoHash;
	std::map<struct node *, int>::iterator it;

	//Result queue for returning 
	std::queue<struct node *> *qToRetPtr =  new std::queue<struct node *>;
	

	levelInfoHash[root] = 1;
	q1.push(root);

	while(!q1.empty())
	{
		struct node *cur = q1.front();
		q1.pop();
		int curLevelNumber = 0;
		it = levelInfoHash.find(cur);

		if(it != levelInfoHash.end())
		{
			//Found
			curLevelNumber = it->second;
		}
		else
		{
			cout<<"Debug level number not found error"<<endl;
			return NULL;
		}
		
		if(levelNumber == curLevelNumber)
		{
			//Found level to print
			cout<<" "<<cur->data;
			qToRetPtr->push(cur);
		}
		else if(levelNumber < curLevelNumber)
		{
			break;
		}
		
		
		if(cur->left)
		{
			//Prepare level number for next level
			levelInfoHash[cur->left] = curLevelNumber + 1;
			q1.push(cur->left);
		}
		
		if(cur->right)
		{
			//Prepare level number for next level
			levelInfoHash[cur->right] = curLevelNumber + 1;
			q1.push(cur->right);
		}

		
	}

	
	cout<<endl;		
	return (void *)qToRetPtr;


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

void printQueue(std::queue<struct node *> *qPrint)
{
	if(qPrint == NULL)
	{
		return;
	}

	while(! (qPrint->empty()) )
	{
		cout<<" " <<qPrint->front()->data;
		qPrint->pop();
	}
	cout<<endl;
}


/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	std::queue<struct node *> *qRet; 

	cout<<"Test 1, Level 2 elems: "<<endl;
	qRet = (std::queue<struct node *> *) printandReturnLevelTree(root, 2);
	cout<<"print queue details"<<endl;
	printQueue(qRet);
	cout<<endl;

	cout<<"Test 2, Level 3 elems: "<<endl;
	qRet = (std::queue<struct node *> *) printandReturnLevelTree(root, 3);
	cout<<"print queue details"<<endl;
	printQueue(qRet);
	
	cout<<"Test 3, Level 4 elems: "<<endl;
	qRet = (std::queue<struct node *> *) printandReturnLevelTree(root, 4);
	cout<<"print queue details"<<endl;
	printQueue(qRet);

	cout<<"Test 4, Level 5 elems: "<<endl;
	qRet = (std::queue<struct node *> *) printandReturnLevelTree(root, 5);
	cout<<"print queue details"<<endl;
	printQueue(qRet);


	cout<<"Test 5, Level 1 elems: "<<endl;
	qRet = (std::queue<struct node *> *) printandReturnLevelTree(root, 1);
	cout<<"print queue details"<<endl;
	printQueue(qRet);



	

	return 0;
}
