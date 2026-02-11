class Solution {
public:
     int solve(int i , int j,vector<vector<int>>&dp,vector<vector<int>>&g){
        if(i<0 || j<0){
            return 0;
        }
        if(g[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=solve(i-1,j,dp,g);
        int right=solve(i,j-1,dp,g);
        return dp[i][j]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
    }
};