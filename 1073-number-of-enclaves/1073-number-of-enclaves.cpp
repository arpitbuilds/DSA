class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};
            for (int i = 0; i< 4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};