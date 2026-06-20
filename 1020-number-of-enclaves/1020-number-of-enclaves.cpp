class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;
        int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 &&
                !vis[nr][nc]) {
                solve(nr, nc, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>v(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (grid[i][j] == 1 && !v[i][j]) {
                        solve(i, j, grid, v);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !v[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};