class Solution {
public:
    bool solve(int ind, int i, int j, vector<vector<int>>& vis, string w,
               vector<vector<char>>& b) {
        int m = b.size();
        int n = b[0].size();
        if (ind == w.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || w[ind] != b[i][j] ||
            vis[i][j]) {
            return false;
        }
        vis[i][j] = 1;
        int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];
            if (solve(ind+1, nr, nc, vis, w, b)) {
               return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& b, string word) {
        int m = b.size();
        int n = b[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == word[0]) {
                    if (solve(0, i, j, vis, word, b)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};