// https://leetcode.com/problems/path-sum-ii/
#include"62_binary_tree.cpp"
class Solution {
public:
    void solve(Node* root,int sum,int targetsum,vector<int> path,vector<vector<int>> &ans){
        if(root==NULL){
            return ;
        }

        sum=sum+root->data;
        path.push_back(root->data);
        if(root->left==NULL && root->right==NULL && sum==targetsum){
            ans.push_back(path);
            return ;
        }

        solve(root->left,sum,targetsum,path,ans);
        solve(root->right,sum,targetsum,path,ans);
        
    }

    vector<vector<int>> pathSum(Node* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,0,targetSum,path,ans);
        return ans;
    }
};