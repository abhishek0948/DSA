// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
#include"62_binary_tree.cpp"
class Solution{
  public:
    pair<int,int> solve(Node* root){
        //base case
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftans=solve(root->left);
        pair<int,int> rightans=solve(root->right);
        
        pair<int,int> res;
        res.first=root->data + leftans.second + rightans.second;
        res.second=max(leftans.first,leftans.second) + max(rightans.first,rightans.second);
        
        return res;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};