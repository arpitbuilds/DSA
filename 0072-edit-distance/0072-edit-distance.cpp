class Solution {
public:
    int solve(int i, int j, string w1, string w2, vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (w1[i] == w2[j]) {
            return dp[i][j] = 0 + solve(i - 1, j - 1, w1, w2,dp);
        } else {
            return dp[i][j] = 1 + min({solve(i - 1, j, w1, w2,dp),
                                       solve(i - 1, j - 1, w1, w2,dp),
                                       solve(i, j - 1, w1, w2,dp)});
        }
    }
    int minDistance(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, w1, w2, dp);
    }
};