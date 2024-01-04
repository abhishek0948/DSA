#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
//-----------------------------------------------------------------------------------------------------------
//Approach 1 : O(n2) as height fun is also called
// class Solution{
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     int height(Node* root){
//         if(!root) return 0;
        
//         int l=height(root->left);
//         int r=height(root->right);
//         int ans=max(l,r)+1;
//         return ans;
//     }
//     bool isBalanced(Node *root)
//     {
//         if(root==NULL) return true;
//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);
        
//         bool diff=abs(height(root->left) - height(root->right))<=1;
        
//         if(left && right && diff) return true;
//         else return false;
//     }
// };
//------------------------------------------------------------------------------------------------------------
//Approach 2 : O(n) 
// class Solution{
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     pair<bool,int> isBalancedfast(Node* root){
//         if(root==NULL) {
//             pair<bool,int> p=make_pair(true,0);
//             return p;
//         }
        
//         pair<bool,int> left=isBalancedfast(root->left);
//         pair<bool,int> right=isBalancedfast(root->right);
        
//         bool l=left.first;
//         bool r=right.first;
//         bool diff=abs(left.second - right.second)<=1;
        
//         pair<bool,int> ans;
//         ans.second=max(left.second,right.second)+1;
        
//         if(l && r && diff) {
//             ans.first=true;
//         }
//         else{
//             ans.first=false;
//         }
//         return ans;
//     }
//     bool isBalanced(Node *root)
//     {
//         return isBalancedfast(root).first;
//     }
// };
