class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};

    void bfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& safe) {
        int m = board.size();
        int n = board[0].size();
        safe[r][c] = true;

        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    board[nrow][ncol] != 'X' && !safe[nrow][ncol]) {
                    safe[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        // if (m == 0) return;
        int n = board[0].size();

        vector<vector<bool>> safe(m, vector<bool>(n, false));

        // Run BFS from the border 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O' && !safe[i][j]) {
                        bfs(i, j, board, safe);
                    }
                }
            }
        }

 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !safe[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
