class Solution {
public:
    // int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
    //     if (i == 0 || j == 0) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     if (s[i - 1] == t[j - 1]) {
    //         return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
    //     } else {
    //         return dp[i][j] = 0 + max(solve(i - 1, j, s, t, dp),
    //                                   solve(i, j - 1, s, t, dp));
    //     }
    // }
    int longestCommonSubsequence(string s, string t) {
        int l = s.length();
        int m = t.length();
        vector<vector<int>> dp(l + 1, vector<int>(m + 1, 0));
        // return solve(l , m , s, t,dp);
        for (int i = 0; i <= l; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l][m];
    }
};