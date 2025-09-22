class Solution {
public:
    int solve(int m, int n, string &s, string &t, vector<vector<int>>& dp, int &ans) {
        if (m == 0 || n == 0) return 0;

        if (dp[m][n] != -1) return dp[m][n];

        if (s[m - 1] == t[n - 1]) {
            dp[m][n] = 1 + solve(m - 1, n - 1, s, t, dp, ans);
            ans = max(ans, dp[m][n]);   // update max length
            return dp[m][n];
        } else {
            return dp[m][n] = 0;  // reset because substring must be contiguous
        }
    }

    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = 0;

        // try all ending positions
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                solve(i, j, s1, s2, dp, ans);
            }
        }

        return ans;
    }
};
