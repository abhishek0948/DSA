#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/sum-tree/1
class Solution
{
    public:
    pair<bool,int> findans(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
           //if leaf node
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftans=findans(root->left);
        pair<bool,int> rightans=findans(root->right);
        
        bool isleftsum=leftans.first;
        bool isrightsum=rightans.first;
        bool cond = root->data ==leftans.second + rightans.second;
        
        pair<bool,int> ans;
        
        if(isleftsum && isrightsum && cond){
            ans.first=true;
            ans.second=2 * root->data;
        }
        else{
            ans.first=false;
            ans.second=root->data + leftans.second + rightans.second ;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return findans(root).first;
    }
};