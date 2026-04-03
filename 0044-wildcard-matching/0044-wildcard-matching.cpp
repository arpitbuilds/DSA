class Solution {
public:
    bool solve(int m, int n, string &s, string &p,vector<vector<int>>&dp) {
        if (m < 0 && n < 0) {
            return true;
        }
        if (m >= 0 && n < 0) {
            return false;
        }
        if (m < 0 && n >= 0) {
            for (int k = 0; k <= n; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if (p[n] == '?' || s[m] == p[n]) {
            return  dp[m][n]=solve(m - 1, n - 1, s, p,dp);
        }
        if (p[n] == '*') {
            return dp[m][n]=solve(m - 1, n, s, p,dp) || solve(m, n - 1, s, p,dp);
        }
        return dp[m][n]=false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m - 1, n - 1, s, p,dp);
    }
};