class Solution {
public:
   int solve(int m,int n,string s,string t, vector<vector<int>>&dp){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s[m-1]==t[n-1]){
            return dp[m][n]=1+solve(m-1,n-1,s,t,dp);
        }
        return dp[m][n]=max(solve(m-1,n,s,t,dp),solve(m,n-1,s,t,dp));
    }
    int minDistance(string word1, string word2) {
          int w1 = word1.size(),w2 = word2.size(); 
        vector<vector<int>>dp(w1+1,vector<int>(w2+1,-1));
        int n = solve(w1,w2,word1,word2,dp); 
        return w1+w2 - 2*n; 
        
    }
};