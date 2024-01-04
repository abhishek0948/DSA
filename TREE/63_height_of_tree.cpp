
#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
//TC:avg(n) ; SC: O(height) //O(n) ->skewed tree

// class Solution{
//     public:
//     //Function to find the height of a binary tree.
//     int height(struct Node* node){
//         // base case 
//         if(node==NULL) return 0;
        
//         int left=height(node->left);
//         int right=height(node->right);
//         int ans=max(left,right)+1;
        
//         return ans;
//     }
// };