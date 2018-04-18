#include <iostream>
#include<vector>
#include<sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Codec {
public:

    void serializeVect(TreeNode* root, std::vector<int>& answer)
    {
      // cout<<"********2Are we here"<<endl;
        if(root == NULL)
        {
          // cout<<"********3Are we here: "<<endl;
            answer.push_back(-1);
          return;
        }
        
        answer.push_back(root->val);
        serializeVect(root->left, answer);
        serializeVect(root->right, answer);
      
      // cout<<"********1Are we here"<<endl;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        std::vector<int> answer;
        
        serializeVect(root, answer);  
        
        stringstream ss;
        
        for(int i = 0; i < answer.size(); i++)
        {   
            if(i != 0)
            {
                ss << ",";
            }
            ss << answer[i];
        }
        
        std::string ret = ss.str();
        return ret;
        
    }

    TreeNode* deserializeUtil(std::vector<int> res, int& cur)
    {
        if(res.size() == 0 || cur >= res.size())
        {
            return NULL;
        }
        
        if(res[cur] == -1)
        {
            cur++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(res[cur++]);
        root->left = deserializeUtil(res, cur);
        root->right = deserializeUtil(res, cur);

        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        //Build vector
        std::vector<int> res;
        std::stringstream ss(data);
        
        string word;
        while(getline(ss, word, ','))
        {
            res.push_back(stoi(word));
        }
        
        int cur = 0;
        return deserializeUtil(res, cur);
    }
  
  void inorder(TreeNode* root)
  {
    if(root == NULL)
    {
      return;
    }
    inorder(root->left);
    cout<<" " <<root->val;
    inorder(root->right);
  }
    
    
    
};


int main()
{
  
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(2);
  TreeNode *root3 = new TreeNode(3);
  TreeNode *root4 = new TreeNode(4);
  TreeNode *root5 = new TreeNode(5);
  
  
  
  root3->left = root4;
  root3->right = root5;
  root1->left = root2;
  root1->right = root3;
  
  
  
  Codec A;
  
  
  std::string ans = A.serialize(root1);
  
  
  
//   TreeNode* root = A.deserialize(ans);
  
//   cout<<endl;
  
  A.inorder(A.deserialize(ans));
  
  
  
//   cout<<ans;
  
  
  return 0;
  
  
}


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

