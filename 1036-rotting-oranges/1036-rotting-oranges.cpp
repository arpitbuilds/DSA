class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int tm = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    v[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
           for (int i = 0; i < 4; i++) {
                    int nrow = x + delr[i];
                    int ncol = y + delc[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                        v[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                        v[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, t + 1});
                        tm = max(tm, t + 1);
                    }
                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && v[i][j]!=2){
                    return -1;
                }
            }
        }
        return tm;
    }
};