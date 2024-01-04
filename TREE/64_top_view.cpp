#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
         vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,vector<int>> m;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            Node* frontnode=q.front().first;
            int HD=q.front().second;
            
            q.pop();
            
            if(m[HD].size()==0)
                m[HD].push_back(frontnode->data);
            
            if(frontnode->left)
                q.push({frontnode->left,HD-1});
            if(frontnode->right)
                q.push({frontnode->right,HD+1});
        }
        
        for(auto i: m){
            for(auto j:i.second){
                ans.push_back(j);
            }
        }
        
        return ans;
    }

};