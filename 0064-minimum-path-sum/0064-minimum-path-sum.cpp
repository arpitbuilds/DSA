class Solution {
public:
      int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=solve(i-1,j,grid,dp);
        int op2=solve(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+ min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,g,dp);
    }
};