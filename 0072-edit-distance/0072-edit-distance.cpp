class Solution {
public:
    // int solve(int x, int y, string& s, string& w, vector<vector<int>>& dp) {
    //     if (x == 0) {
    //         return y;
    //     }
    //     if (y == 0) {
    //         return x;
    //     }
    //     if (dp[x][y] != -1) {
    //         return dp[x][y];
    //     }
    //     if (s[x - 1] == w[y - 1]) {
    //         return dp[x][y] = 0 + solve(x - 1, y - 1, s, w, dp);
    //     }
    //     int inser = 1 + solve(x, y - 1, s, w, dp);
    //     int del = 1 + solve(x - 1, y, s, w, dp);
    //     int rep = 1 + solve(x - 1, y - 1, s, w, dp);
    //     return dp[x][y] = min({inser, del, rep});
    // }
    int minDistance(string s, string w) {
        int m = s.size();
        int n = w.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        // return solve(n1,n2,w1,w2,dp);
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == w[j - 1]) {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }
                else{
                int inser = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int rep = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({inser, del, rep});
                }
            }
        }
        return dp[m][n];
    }
};