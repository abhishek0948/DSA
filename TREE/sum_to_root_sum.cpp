// https://leetcode.com/problems/sum-root-to-leaf-numbers/
#include"62_binary_tree.cpp"
//Approach 1 : By using inbuilt stoi function
class Solution {
public:
    int sumNumbers(Node* root, string number = "") {
        if (!root)
            return 0;

        number += std::to_string(root->data);

        if (!root->left && !root->right)
            return stoi(number);

        int result1 = sumNumbers(root->left, number);
        int result2 = sumNumbers(root->right, number);

        return result1 + result2;
    }
};
//---------------------------------------------------------------------------------------------------------------
//Approach 2 : without using vector
class Solution {
private:
void solve(Node* root,int &sum,int &ans){
    if(root->left==NULL && root->right==NULL){
        sum=sum*10+root->data;
        ans=ans+sum;
        sum=sum/10;
        return;
    }
    sum=sum*10+root->data;
    if(root->left){
        solve(root->left,sum,ans);
    }
    if(root->right){
        solve(root->right,sum,ans);
    }
    sum=sum/10;
}
public:
    int sumNumbers(Node* root) {
        int sum=0,ans=0;
        solve(root,sum,ans);
        return ans;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Using vector
class Solution {
public:
    int convert(vector<int> paths){
        int n=paths.size();
        int num=0;
        for(int i=0;i<n;i++){
            num=num+pow(10,n-1-i)*paths[i];
        }
        return num;
    }
    void solve(Node* root,vector<int> &paths,int &total){
        if(root==NULL){
            return ;
        }

        paths.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            int num=convert(paths);
            // cout<<num<<" ";
            total=total+num;
            paths.pop_back();
            return ;
        }

        solve(root->left,paths,total);
        solve(root->right,paths,total);

        paths.pop_back();
    }
    int sumNumbers(Node* root) {
        vector<int> paths;
        int total=0;
        solve(root,paths,total);
        return total;
    }
};