//https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
#include "BST.cpp"
using namespace std;
class Solution {
  public:
    int countNode(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int ans=1 + countNode(root->left) + countNode(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* tree,int index,int nodes){
        if(!tree){
            return true;
        }
        
        if(index >= nodes){
            return false;
        }
        
        else{
            bool left=isCBT(tree->left,2*index + 1,nodes);
            bool right=isCBT(tree->right,2*index + 2,nodes);
            
            return left && right;
        }
    }
    
    bool isMax(struct Node* root){
        if(!root->left && !root->right){
            return true;
        }
        
        if(root->right==NULL){
            return (root->data >= root->left->data);
        }
        
        else{
            bool left=isMax(root->left);
            bool right=isMax(root->right);
            
            return (left) && (right) && (root->data >= root->left->data) && (root->data >= root->right->data);
        }
    }
    bool isHeap(struct Node* tree) {
        int index=0;
        int nodes=countNode(tree);
        
        if(isCBT(tree,index,nodes) && isMax(tree)){
            return true;
        }
        
        else{
            return false;
        }
    }
};