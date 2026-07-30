class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp) {
         if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return g[i][j];
        }
      
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int op1=solve(i-1,j,g,dp);
       int op2=solve(i,j-1,g,dp);
       return dp[i][j]=g[i][j]+min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, g, dp);
    }
};