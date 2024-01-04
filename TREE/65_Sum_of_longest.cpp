// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
#include"62_binary_tree.cpp"
class Solution
{
public:
    void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){
        if(root==NULL){
            
            if(len > maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(sum,maxsum);
            }
            return ;
        }
        
        sum=sum+root->data;
        
        solve(root->left,sum,maxsum,len+1,maxlen);
        solve(root->right,sum,maxsum,len+1,maxlen);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum=0;
        int maxsum=0;
        int len=0;
        int maxlen=0;
        
        solve(root,sum,maxsum,len,maxlen);
        
        return maxsum;
    }
};