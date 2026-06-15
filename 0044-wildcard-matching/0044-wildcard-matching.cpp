class Solution {
public:
    bool solve(int i, int j, string &s, string &t,vector<vector<int>>&dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (j < 0 && i >= 0) {
            return false;
        }
        if (i < 0 && j >= 0) {
            for (int k = j; k >= 0; k--) {
                if (t[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (s[i] == t[j] || t[j] == '?') {
            return dp[i][j]=solve(i - 1, j - 1, s, t,dp);
        } else if (t[j] == '*') {
            return dp[i][j]=solve(i - 1, j, s, t,dp) || solve(i, j - 1, s, t,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m - 1, n - 1, s, p,dp);
    }
};