class Solution {
public:
    bool check(int r, int c, vector<string>& v, int n) {
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
        while (r < n && c >= 0) {
            if (v[r++][c--] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(int c, int n, string s,vector<string>&v, vector<vector<string>>& ans) {
        if (c == n) {
            ans.push_back(v);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (check(r, c, v,n)) {
                v[r][c] = 'Q';
                solve(c + 1, n, s,v,ans);
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
        solve(0, n, s,v, ans);
        return ans;
    }
};