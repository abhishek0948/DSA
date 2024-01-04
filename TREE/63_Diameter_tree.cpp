#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
//---------------------------------------------------------------------------------------------------------------
//pair(diameter,height) this does not call height fun and TC: O(n)
// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
//     pair<int,int> diameterfast(struct Node* root){
//     //base case 
//     if(root==NULL){
//         pair<int,int> p=make_pair(0,0);
//         return p;
//     }
    
//     pair<int,int> left=diameterfast(root->left);
//     pair<int,int> right=diameterfast(root->right);
    
//     int op1=left.first;
//     int op2=right.first;
//     int op3=left.second+right.second+1;
    
//     pair<int,int> ans;
//     ans.first=max(op1,max(op2,op3));
//     ans.second=max(left.second , right.second)+1;
    
//     return ans;
    
// }
// int diameter(struct Node* root) {
//     pair<int,int> p=diameterfast(root);
//     return p.first;
// }
// };
//-----------------------------------------------------------------------------------------------------------------
//TC:O(n2) as height fun is also called
// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int height(Node* root){
//         if(root==NULL) return 0;
        
//         int lh=height(root->left);
//         int rh=height(root->right);
//         int ans=max(lh,rh)+1;
//         return ans;
//     }
    
//     int diameter(Node* root) {
//         if(root==NULL) return 0;
        
//         int op1=diameter(root->left);
//         int op2=diameter(root->right);
//         int op3=height(root->left)+height(root->right)+1;
        
//         int ans=max(op1,max(op2,op3));
//         return ans;
//     }
// };