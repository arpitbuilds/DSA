class Solution {
public:
    int solve(int m,int n, string &s,string &p,vector<vector<int>>&dp){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s[m-1]==p[n-1]){
            return dp[m][n]=1+solve(m-1,n-1,s,p,dp);
        }
        int op1=solve(m-1,n,s,p,dp);
        int op2=solve(m,n-1,s,p,dp);
        return dp[m][n]=max(op1,op2);
    }
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string p=s;
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        reverse(s.begin(),s.end());
        return solve(m,m,s,p,dp);
    }
};