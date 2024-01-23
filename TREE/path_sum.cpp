// https://leetcode.com/problems/path-sum/
#include"62_binary_tree.cpp"
class Solution {
public:
    bool isleaf(Node* root){
        if(!root->left && !root->right)
            return  true;

        return false;
    }
    bool solve(Node* root,int targetsum,int sum){
        if(root==NULL)
            return false;
        
        sum=sum+root->data;
        if(sum==targetsum && isleaf(root)){
            return true;
        }

        bool leftans=solve(root->left,targetsum,sum);
        bool rightans=solve(root->right,targetsum,sum);

        return leftans || rightans;
    }
    bool hasPathSum(Node* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
    }
};