class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& t,
              int n) {
        if (i == n - 1) {
            return t[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = solve(i + 1, j, dp, t, n);
        int diag = solve(i + 1, j + 1, dp, t, n);
        return dp[i][j] = t[i][j] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return solve(0, 0, dp, triangle, n);
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = t[n-1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j]=t[i][j]+min(down,diag);
            }
        }
        return dp[0][0];
    }
};