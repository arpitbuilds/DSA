class Solution {
public:
    bool solve(int x, int y, string &s, string &p, vector<vector<int>>& dp) {
        if (x < 0 && y < 0) {
            return true;
        }
        if (x < 0 && y >= 0) {
            for (int k = 0; k <= y; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (x >= 0 && y < 0) {
            return false;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        if (s[x] == p[y] || p[y] == '?') {
            return dp[x][y]=solve(x - 1, y - 1, s, p, dp);
        }
        if (p[y] == '*') {
            return dp[x][y]=solve(x - 1, y, s, p, dp) || solve(x, y - 1, s, p, dp);
        }
        return dp[x][y]=false;
    }
    bool isMatch(string s, string p) {
        int x = s.size();
        int y = p.size();
        vector<vector<int>> dp(x, vector<int>(y, -1));
        return solve(x - 1, y - 1, s, p, dp);
    }
};