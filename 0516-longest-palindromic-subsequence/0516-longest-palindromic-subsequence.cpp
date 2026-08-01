class Solution {
public:
       int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        }
        int op1=solve(i-1,j,s,t,dp);
        int op2=solve(i,j-1,s,t,dp);
        return dp[i][j]=max(op1,op2);
    }
    int longestPalindromeSubseq(string s) {
       int m=s.size();
       string t=s;
       reverse(s.begin(),s.end());
       vector<vector<int>>dp(m,vector<int>(m,-1));
       return solve(m-1,m-1,s,t,dp); 
    }
};