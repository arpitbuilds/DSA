class Solution {
public:
    bool safe(int r, int c, vector<string>& v, int n) {
        int tr = r;
        int tc = c;
        while (r >= 0 && c >= 0) {
            if (v[r--][c--] == 'Q') {
                return false;
            }
        }
        r = tr;
        c = tc;
        while (c >= 0) {
            if (v[r][c--] == 'Q') {
                return false;
            }
        }
        r = tr;
        c = tc;
        while (c >= 0 && r < n) {
            if (v[r++][c--] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(int c, vector<vector<string>>& ans, vector<string>& v, int n) {
        if (c == n) {
            ans.push_back(v);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (safe(r, c, v, n)) {
                v[r][c] = 'Q';
                solve(c + 1, ans, v, n);
                v[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            v[i] = s;
        }
        solve(0, ans, v, n);
        return ans;
    }
};