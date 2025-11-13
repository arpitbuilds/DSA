class Solution {
public:
    int solve(int x, int y, string s, string t, vector<vector<int>>& dp) {
        // if (x == 0 || y == 0) {
        //     return 0;
        // }
        // if (dp[x][y] != -1) {
        //     return dp[x][y];
        // }
        // if (s[x - 1] == t[y - 1]) {
        //     return dp[x][y] = 1 + solve(x - 1, y - 1, s, t, dp);
        // } else {
        //     return dp[x][y] = 0 + max(solve(x - 1, y, s, t, dp),
        //                               solve(x, y - 1, s, t, dp));
        // }
        for (int i = 0; i <= x; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= y; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
   
    int minInsertions(string s) {
         string t = s;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        reverse(s.begin(), s.end());
        int pn =  solve(n, n, s, t, dp);
        return n - pn;
    }
};