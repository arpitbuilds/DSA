class Solution {
public:
    int solve(int i, int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i-1]==t[j-1]){
            return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        }
        int op1=solve(i-1,j,s,t,dp);
        int op2=solve(i,j-1,s,t,dp);
        return dp[i][j]=max(op1,op2);
    }
    int longestCommonSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,s,t,dp);
    }
};