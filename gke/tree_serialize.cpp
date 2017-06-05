/**
 * Definition for a binary tree node.

 */

#include<iostream>
#include<climits>
using namespace std;



struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    void serializeUtil(TreeNode *root, string &resV) {
        
        if(root == NULL) {
            resV.push_back(',');
            resV.push_back('s');
            return;
        }
        
        resV.push_back(',');
        string rootVal = std::to_string(root->val);
        
        resV += rootVal;
        serializeUtil(root->left, resV);
        serializeUtil(root->right, resV);
        return;
        
    }
    string serialize(TreeNode* root) {
        
        string cur = "";
        if(root == NULL) {
            return "";
        }
        string resV;
        serializeUtil(root, resV);
        resV = resV.substr(1);
        // cout<<resV<<endl;
        return resV;
        
    }

    
    int findNumber(string data, int &pos) {
        
        int num = INT_MAX;
        
        int endPos = pos;
        while((endPos < data.size()) && (data[endPos] != ',')) {
            endPos++;
        }
        if(data[endPos] == ',') {
            endPos--;
        }
        // cout<<"Start pos: "<<pos<<" end pos: "<<endPos<<endl;
        
        while(pos <= endPos) {
            int curDigit = (int)(data[pos++] - '0');
            // cout<<"CurDigit is: "<<curDigit<<endl;
            if(num == INT_MAX) {
                num = curDigit;
            } else {
                num *= 10;
                num += curDigit;
            }
        }  
        
        // cout<<"Number formed: "<<num<<endl;
        return num;
        
  
        
    }

    TreeNode *deserializeUtil(string data, int &pos) {
        
        int curVal = 0;
        
        if(pos >= data.size()) {
            return NULL;
        }
        
        if(data[pos] == ',') {
            pos++;
        }
        
        if(data[pos] == 's') {
            pos++;
            return NULL;
        }
        
        if(data[pos] == '-') {
            pos++;
            curVal = findNumber(data, pos);
            curVal = - curVal;
        } else {
            curVal = findNumber(data, pos);
        }
 
        // cout<<"Yo "<<data[pos]<<endl;
        
        // cout<<"curVal is : "<<curVal<<endl;
        TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        root->val = curVal;
        root->left = deserializeUtil(data, pos);
        root->right = deserializeUtil(data, pos);
        return root;
        
        
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) {
            return NULL;
            
        }
        int start = 0;
        TreeNode* root = deserializeUtil(data, start);
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



int main(int argc, char const *argv[])
{
    cout<<"Check out lc"<<endl;
    return 0;
}
