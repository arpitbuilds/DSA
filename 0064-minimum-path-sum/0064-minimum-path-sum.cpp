class Solution {
public:
    int solve(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return INT_MAX;
        }
        if(m==0 && n==0){
            return grid[m][n];
        }
        if(dp[m][n]!=-1){
             return dp[m][n];
        }
        int op1=solve(m-1,n,grid,dp);
        int op2=solve(m,n-1,grid,dp);
        return dp[m][n]=grid[m][n]+min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};