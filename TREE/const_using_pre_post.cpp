// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
#include"62_binary_tree.cpp"
class Solution {
public:
    Node* dfs(vector<int>& preorder,int prestart,int preend, vector<int>& postorder,int poststart,int postend)
    {
        if(prestart>preend)
        {
            return NULL;
        }
        if(poststart>postend)
        {
            return NULL;
        }
        Node* root=new Node(preorder[prestart]);
        if(prestart==preend)
        {
            return root;
        }
        int postindex=poststart;
        while(postorder[postindex]!=preorder[prestart+1])
        {
            postindex++;
        }
        int len= postindex-poststart+1;
        root->left=dfs(preorder,prestart+1,prestart+len,postorder,poststart,postindex);
        root->right=dfs(preorder,prestart+len+1,preend,postorder,postindex+1,postend-1);
        return root;

    }
    Node* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return dfs(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};