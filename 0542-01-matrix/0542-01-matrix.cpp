class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m,vector<int>(n));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c] = d;
            int delr[] = {0, -1, 0, 1};
            int delc[] = {-1, 0, 1, 0};
            for (int k = 0; k < 4; k++) {
                int nr = r + delr[k];
                int nc = c + delc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                    mat[nr][nc] == 1) {
                    q.push({{nr, nc}, d + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return dist;
    }
};