

/* Print zig zag */

/* 

       1

   2       3

4     5  6     7


=> 1
   2  3
   7 6 5 4


Use two stacks

while processing s1 stack, store children reverse order 
for s2
while processing s2 stack, store same order 
children for s1



*/



/* 
Debug learnings:

1. Remember flag and data structure initializing and change
conditions

For e.g., Line 143

if(isReverse)
      {
          sToUse = &s2;
          sToPush = &s1;
      }
      
 */     
      





#include<iostream>
#include<stack>




using namespace std;

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};


struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}


void printSpiral(struct node *root)
{
 
  if(root == NULL)
  {
    return;
  }
  
  std::stack<struct node *> s1, s2;
  std::stack<struct node *> *sToUse, *sToPush;
  
  s1.push(root);
  
  sToUse = &s1;
  sToPush = &s2;
  bool isReverse = true;
  
  while(!(sToUse->empty()))
  {
    
   struct node *cur = sToUse->top();
    sToUse->pop();
    
    if(cur == NULL)
    {
      cout<<"Debug 1 empty cur"<<endl;
      return;
    }
    
    cout<<" "<<cur->data;
    
    if(isReverse)
    {
      if(cur->right)
      {
        sToPush->push(cur->right);
      }
      
      if(cur->left)
      {
        sToPush->push(cur->left);
      }
    }
    else
    {
    
      if(cur->left)
      {
        sToPush->push(cur->left);
      }
      
      if(cur->right)
      {
        sToPush->push(cur->right);
      }
    }
    
    //Reset the stacks 
    if(sToUse->empty())
    {
      cout<<endl;
      
      if(isReverse)
      {
          sToUse = &s2;
          sToPush = &s1;
      }
      else
      {
          sToUse = &s1;
          sToPush = &s2; 
      }
      
      isReverse = !isReverse;
      
    }

 
    
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
    printSpiral(root);
 
    return 0;
}








