#include"62_binary_tree.cpp"
// https://www.geeksforgeeks.org/problems/k-sum-paths/1
//Approach 1 : TC : O(N2)
class Solution{
  public:
    void solve(Node* root,int k,int &count,vector<int> path){
        //base case
        if(root==NULL) return ;
        
        path.push_back(root->data);
        //left
        solve(root->left,k,count,path);
        //right
        solve(root->right,k,count,path);
        //Check for k  sum
        int sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==k)
                count++;
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count=0;
        solve(root,k,count,path);
        return count;
    }
};
//-----------------------------------------------------------------------------------------------------
//Approach 2 : By using prefix sum , TC : O(n)
class Solution{
  public:
    const int mod = 1e9 + 7;
    int total = 0;
    void solve(Node *root, int k, int sum, unordered_map<int, int> &prefix){
        if(!root){
            return;
        }
        sum += root -> data;
        total = (total + prefix[sum - k]);
        prefix[sum]++;
        solve(root -> left, k, sum, prefix);
        solve(root -> right, k, sum, prefix);
        prefix[sum]--;
    }
    int sumK(Node *root, int k){
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        solve(root, k, 0, prefix);
        return total;
    }
};