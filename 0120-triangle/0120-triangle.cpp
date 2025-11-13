class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&t,vector<vector<int>>&dp,int n){
        if(i==n-1){
            return t[i][j];
        }
        if(j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=solve(i+1,j,t,dp,n);
        int op2=solve(i+1,j+1,t,dp,n);
        return dp[i][j]=t[i][j]+min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp,n);
    }
};