#include<bits/stdc++.h>
using namespace std;
//TC : O(m*n)
class Solution {
public:
    int solve(vector<vector<int>> & dp, vector<vector<int>> &grid, int row, int col) {
        if(row == 0 && col == 0) return grid[0][0];
        if(row < 0 || col < 0) return INT_MAX;
        if(dp[row][col] != 0) return dp[row][col];

        return dp[row][col] = grid[row][col] + min(solve(dp, grid, row - 1, col), solve(dp, grid, row, col - 1));

    }
    int minPathSum(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        return solve(dp, grid, m-1, n-1);

    }
};
//--------------------------------------------------------------------------------------------
//Tabulation : TC : O(m*n) 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};