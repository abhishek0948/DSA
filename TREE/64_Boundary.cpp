#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1  
class Solution {
public:
    void traverseleft(Node* root,vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        
        ans.push_back(root->data);
        if(root->left)
            traverseleft(root->left,ans);
        else 
            traverseleft(root->right,ans);
    }
    
    void traverseleaf(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    
    void traverseright(Node* root,vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        
        if(root->right) traverseright(root->right,ans);
        else traverseright(root->left,ans);
        
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        
        //left part excluding leaf
        traverseleft(root->left,ans);
        
        //leaf node
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        
        //Rightpart excluding leaf
        traverseright(root->right,ans);
        
        return ans;
    }
};