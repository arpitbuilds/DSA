class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (!vis[i][j] && board[i][j] == 'O') {
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
            int delr[] = {0, -1, 0, 1};
            int delc[] = {-1, 0, 1, 0};
            for (int k = 0; k < 4; k++) {
                int nrow = r + delr[k];
                int ncol = c + delc[k];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    !vis[nrow][ncol] && board[nrow][ncol]=='O') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};