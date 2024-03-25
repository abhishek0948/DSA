// https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;
//Structure for Tree
class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
//-----------------------------------------------------------------------------------------------
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode* root,int &ans){
    if(root==NULL){
      return { INT_MIN, INT_MAX, true, 0 };
    }

    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    currNode.size=left.size + right.size + 1;

    if(left.isBST && right.isBST && (root->data  > left.maxi && root->data < right.mini)){
        currNode.isBST=true;
    }
    
    else{
        currNode.isBST=false;
    }

    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode * root){
    
    int ans=0;
    info temp=solve(root,ans);
    return ans;
}