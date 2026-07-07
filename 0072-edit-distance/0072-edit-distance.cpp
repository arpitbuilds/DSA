class Solution {
public:
    int solve(int m, int n,string &s,string &t,vector<vector<int>>&dp){
        if(m<0){
            return n+1;
        }
        if(n<0){
            return m+1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s[m]==t[n]){
            return dp[m][n]=0+solve(m-1,n-1,s,t,dp);
        }
        else{
            return dp[m][n]=1+min({solve(m,n-1,s,t,dp),solve(m-1,n,s,t,dp),solve(m-1,n-1,s,t,dp)});
        }
    }
    int minDistance(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};