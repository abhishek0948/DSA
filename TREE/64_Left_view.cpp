#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
//--------------------------------------------------------------------------------------
//Iterative approach 
vector<int> leftView(Node *root)
{
   //Function to return a list containing elements of left view of the binary tree.
   vector<int> ans;
   if(root==NULL) return ans;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int size=q.size();
       vector<int> temp;
       
       for(int i=0;i<size;i++){
           Node* frontnode=q.front();
           q.pop();
           
           temp.push_back(frontnode->data);
           if(frontnode->left) 
                q.push(frontnode->left);
           if(frontnode->right) 
                q.push(frontnode->right);
       }
       ans.push_back(temp[0]);
   }
   return ans;
}
//-----------------------------------------------------------------------------------------------------
// Recurrsive Approach
void solve(Node* root,vector<int> &ans,int level){
    if(root==NULL) return ;
    //new level started
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   //Function to return a list containing elements of left view of the binary tree.
   vector<int> ans;
   if(root==NULL) return ans;
   
   solve(root,ans,0);
   
   return ans;
}
//-----------------------------------------------------------------------------------------------------
