  class Solution {
public:
    bool check(int r, int c, int n, vector<string>& v,
               vector<vector<string>>& ans) {
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
    void solve(int c, int n,vector<string>& v, vector<vector<string>>& ans) {
        if (c == n) {
            ans.push_back(v);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (check(r, c, n, v, ans)) {
                v[r][c] = 'Q';
                solve(c + 1, n, v, ans);
                v[r][c] = '.';
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<string>> ans;
        string s = string(n, '.');
        vector<string>v(n);
        for (int i = 0; i < n; i++) {
            v[i] = s;
        }
        solve(0, n, v, ans);
        return ans.size();
    }
};