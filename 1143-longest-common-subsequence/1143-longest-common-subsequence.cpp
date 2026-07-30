class Solution {
public:
    int solve(int m , int n,string &s,string &t,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return 0;
        }
        if(s[m]==t[n]){
            return 1+solve(m-1,n-1,s,t,dp);
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int op1=solve(m-1,n,s,t,dp);
        int op2=solve(m,n-1,s,t,dp);
        return dp[m][n]=max(op1,op2);
    }
    int longestCommonSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};