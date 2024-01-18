// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
#include<bits/stdc++.h>
#include"62_binary_tree.cpp"
//Approach 1 : using a vector (extra space)
vector <int> result;
void Ancestor(Node *root,int node,vector <int> &ans){
    if(root==NULL){
        return;
    }
    if(root->data==node){
        result = ans;
        return;
    }
    ans.push_back(root->data);
    Ancestor(root->left,node,ans);
    Ancestor(root->right,node,ans);
    ans.pop_back();
}
int kthAncestor(Node *root, int k, int node){
    vector <int> ans;
    Ancestor(root,node,ans);
    int n = result.size();
    if(!result.empty() && result.size()>=k){
        return result[n - k];
    }
    return -1;
}
//-----------------------------------------------------------------------------------------------------
//Approach 2 : Without extra space (not including fun stack)
Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}
 