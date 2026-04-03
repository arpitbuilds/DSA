class Solution {
public:
    int lcs(int m, int n, string &p, string &s,vector<vector<int>>&dp) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        if (p[m - 1] == s[n - 1]) {
            return dp[m][n] = 1 + lcs(m - 1, n - 1, p, s,dp);
        }
        return dp[m][n] = max(lcs(m - 1, n, p, s,dp), lcs(m, n - 1, p, s,dp));
    }
    int longestPalindromeSubseq(string s) {
        string p = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int k = lcs(n, n, p, s,dp);
        return k;
    }
};