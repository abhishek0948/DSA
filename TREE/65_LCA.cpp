#include"62_binary_tree.cpp"
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL) return NULL;
        if(root->data==n1 || root->data==n2) return root;
        
        Node* leftans=lca(root->left,n1,n2);
        Node* rightans=lca(root->right,n1,n2);
        
        if(leftans && rightans) return root;
        else if(leftans && !rightans) return leftans;
        else if(!leftans && rightans) return rightans;
        else return NULL;
    }
};