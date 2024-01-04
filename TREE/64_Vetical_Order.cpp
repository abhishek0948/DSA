#include"62_binary_tree.cpp"
// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
//TC : O(n*logn)
class solution{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {        
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,vector<int>> m;  //To store map of HD and its elements
        queue<pair<Node*,int>> q;  //To traverse by HD , <Node,HD>
        q.push({root,0});
        
        while(!q.empty()){
            Node* frontnode=q.front().first;  
            int horizontaldist=q.front().second;
            
            q.pop();
            m[horizontaldist].push_back(frontnode->data);
            
            if(frontnode->left)
                q.push({frontnode->left,horizontaldist-1});
            if(frontnode->right)
                q.push({frontnode->right,horizontaldist+1});
                
        }
        
        for(auto i:m){
            for(auto j:i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};