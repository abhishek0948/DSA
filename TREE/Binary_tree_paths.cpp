// https://leetcode.com/problems/binary-tree-paths/
#include"62_binary_tree.cpp"
class Solution {
public:
    void solve(Node* root,string paths,vector<string>& ans){
        if(root==NULL) return;

        string temp=to_string(root->data);
        paths=paths+temp;

        if(root->left==NULL && root->right==NULL){
            ans.push_back(paths);
            return ;
        }
        else{
            paths.push_back('-');
            paths.push_back('>');
        }

        solve(root->left,paths,ans);
        solve(root->right,paths,ans);

    }
    vector<string> binaryTreePaths(Node* root) {
        vector<string> ans;
        string paths="";

        solve(root,paths,ans);

        return ans;
    }
};