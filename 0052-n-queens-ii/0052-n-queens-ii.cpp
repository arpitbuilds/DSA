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
    void solve(int c, int& cnt, int n, vector<string>& v, string s) {
        if (c == n) {
            cnt++;
            return;
        }
        for (int r = 0; r < n; r++) {
            if (check(r, c, v, n)) {
                v[r][c] = 'Q';
                solve(c + 1, cnt, n, v, s);
                v[r][c] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string>v(n);
        for (int i = 0; i < n; i++) {
            v[i] = s;
        }
        int cnt = 0;
        solve(0, cnt, n, v, s);
        return cnt;
    }
};