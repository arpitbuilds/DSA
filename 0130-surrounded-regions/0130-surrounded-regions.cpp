class Solution {
public:
    void solve(int r, int c, vector<vector<char>>& b,
               vector<vector<int>>& vis) {
        int m = b.size();
        int n = b[0].size();
        vis[r][c] = 1;
        int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = r + delr[k];
            int nc = c + delc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && b[nr][nc] == 'O' &&
                !vis[nr][nc]) {
                solve(nr, nc, b, vis);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int m = b.size();
        int n = b[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (b[i][j] == 'O' && !vis[i][j]) {
                        solve(i, j, b, vis);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]=='O' && !vis[i][j]){
                    b[i][j]='X';
                }
            }
        }
    }
};