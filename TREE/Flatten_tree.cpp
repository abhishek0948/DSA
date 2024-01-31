// https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
#include"62_binary_tree.cpp"
//Approach 1 : By using extra Space SC : O(n);
class Solution
{
    public:
    void solve(Node* root,queue<Node*> &q){
        if(root==NULL)
            return;     
        q.push(root);
        solve(root->left,q);
        solve(root->right,q);   
    }
    
    void ans(Node* root,queue<Node*> &q){   
        q.pop();
        while(!q.empty()){ 
            root->right=q.front();
            q.pop();
            root->left=NULL;
            root=root->right;
        }
    }
    void flatten(Node *root)
    {   
        queue<Node*> q;
        solve(root,q);
        ans(root,q);
    }
};
//------------------------------------------------------------------------------------------------------------
//Approach 2 : TC = O(n) and SC = O(1)
class Solution
{
    public:
    void flatten(Node *root)
    {
        //Morris Traversal is only traversal in tree where Space Coplexity is O(1)
        Node* curr = root;
        
        while(curr != NULL)
        {
            if(curr->left)
            {
                Node* pred = curr->left;
                while(pred->right)
                    pred = pred->right;
                    
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};