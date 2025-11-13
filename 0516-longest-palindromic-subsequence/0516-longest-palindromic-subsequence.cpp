class Solution {
public:
    int solve(int i ,int j,vector<vector<int>>&dp,string &s,string &t){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i-1]==t[j-1]){
            return dp[i][j]=1+solve(i-1,j-1,dp,s,t);
        }
        return dp[i][j]=0+max(solve(i-1,j,dp,s,t),solve(i,j-1,dp,s,t));
    }
    int longestCommonSubsequence(string t1, string t2) {
         int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m +1, vector<int>(n +1, -1));
        return solve(m,n,dp,t1,t2);
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,s1);

    }
};