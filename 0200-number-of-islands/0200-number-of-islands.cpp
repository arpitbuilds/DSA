class Solution {
public:
    void solve(int i, int j, vector<vector<char>>& g,
               vector<vector<int>>& vis) {
        int m = g.size();
        int n = g[0].size();
        vis[i][j]=1;
         int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    g[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++ ;
                     vis[i][j] = 1;
                    solve(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};