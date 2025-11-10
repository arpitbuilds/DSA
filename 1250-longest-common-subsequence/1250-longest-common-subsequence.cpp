class Solution {
public:
    // int solve(int x, int y, string t1, string t2, vector<vector<int>>& dp) {
    //     if (x == 0 || y == 0) {
    //         return 0;
    //     }
    //     if (dp[x][y] != -1) {
    //         return dp[x][y];
    //     }
    //     if (t1[x - 1] == t2[y - 1]) {
    //         return dp[x][y] = 1 + solve(x - 1, y - 1, t1, t2, dp);
    //     }
    //     return dp[x][y] = 0 + max(solve(x - 1, y, t1, t2, dp),
    //                               solve(x, y - 1, t1, t2, dp));
    // }
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // return solve(m,n,t1,t2,dp);
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
        dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};