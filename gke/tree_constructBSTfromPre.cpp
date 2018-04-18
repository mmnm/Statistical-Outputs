#include <iostream>
#include<vector>
using namespace std;


struct node 
{
  int data;
  struct node *left;
  struct node *right;
};


struct node * newNode(int data)
{
  struct node * cur = new node();
  cur->data = data;
  cur->left = cur->right = NULL;
  
  return cur;
}


void printInorder(struct node *root)
{
 
  if(root == NULL)
  {
    return;
  }
  
  printInorder(root->left);
  
  cout<<" " << root->data;
  
  printInorder(root->right);
  
}

  
void printVector(std::vector<int> in)
{
  cout<<endl;
  for(int i = 0; i < in.size(); i++)
  {
    cout<<" " <<in[i];
  }
 
  cout<<endl;
}



struct node* constructBST(std::vector<int> v)
{
  if(v.size() == 0)
  {
    return NULL;
  }
  
  struct node* root = newNode(v[0]);
  
  if(v.size() == 1)
  {
    return root;
  }

  int i = 1;
  while(i < v.size() && v[i] < v[0])
  {
    i++;
  }
  
  cout<<"Value of i: "<<i<<endl;
  cout<<"**************";
  
  std::vector<int> left(v.begin() + 1, 
                        v.begin() + i);

  printVector(left);
  std::vector<int> right(v.begin() + i, v.end());
   printVector(right);
  
  root->left = constructBST(left);
  root->right = constructBST(right);

  return root;
}
  
  



// To execute C++, please define "int main()"
int main() {

  std::vector<int> pre_test1 = {10, 5, 1, 7, 40, 50};
  
  struct node * root = constructBST(pre_test1);
  
  printInorder(root);

  return 0;
}

