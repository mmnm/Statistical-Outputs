/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    
    bool search(TreeNode* root, TreeNode* cur)
    {
        
        if(root == NULL)
        {
            return false;
        }
        cout<<"Testing: "<<cur->val<<" and start node: "<<root->val<<endl;
        
        if(root == cur)
        {
            // cout<<"Found: "<<cur->val<<endl;
            return true;
        }
        
        // if(search(root->left, cur) || search(root->right, cur))
        // {
        //     return true;
        // }
        // return false;        
        return (search(root->left, cur) || search(root->right, cur));
    }

    TreeNode* find_lcaUtil(TreeNode* root, TreeNode* n1, TreeNode* n2, bool& f_n1, bool& f_n2)
    {
        if(root == NULL)
        {
            return NULL;
        }
        bool loc_f_n1 = false;
        bool loc_f_n2 = false;
        
        if(root == n1)
        {
            // cout<<"Found: n1: "<<root->val<<endl;
            f_n1 = true;
            if(search(root, n2))
            {
                return n1;
            }
            else
            {
                return NULL;
            }
        }
        if(root == n2)
        {
            // cout<<"Found: n2: "<<root->val<<endl;
            f_n2 = true;
            if(search(root, n1))
            {
                return n2;
            }
            else
            {
                return NULL;
            }
        }
        
        TreeNode* left_lca = find_lcaUtil(root->left, n1, n2, loc_f_n1, loc_f_n2);
        
        if(left_lca)
        {
            return left_lca;
        }
        
        TreeNode* right_lca = find_lcaUtil(root->right, n1, n2, loc_f_n1, loc_f_n2);
        
        if(right_lca)
        {
            return right_lca;
        }
        
        if(loc_f_n1 && loc_f_n2)
        {
            // cout<<"Node value::f_n1::f_n2::"<<root->val<<"::"<<f_n1<<"::"<<f_n2<<endl;
            return root;
        }
        
             
        if(loc_f_n1)
        {
            f_n1 = loc_f_n1;
        }
        
        if(loc_f_n2)
        {
            f_n2 = loc_f_n2;
        }
        
        return NULL;
         
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
        {
            return root;
        }
        
        bool f_n1 = false;
        bool f_n2 = false;
        
        return find_lcaUtil(root, p, q, f_n1, f_n2);
        
    }
};



int main()
{


    return 0;
}

