#include<bits/stdc++.h>
using namespace std;
//Approach 1 : Bit masking  TC : O (n*(2^n-1))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total_subsets=1<<n;
        vector<vector<int>> subsets;

        for(int mask=0;mask<total_subsets;mask++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if((mask & (1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};

//Approach 2 : Recurrsion TC : O(2^n)
class Solution {
public:
    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){
        //Base case
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }

        //exclude
        solve(nums,output,index+1,ans);

        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};