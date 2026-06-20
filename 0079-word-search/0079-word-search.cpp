class Solution {
public:
    bool dfs(int r, int c, int ind, vector<vector<char>>& b, string word,
             vector<vector<int>>& vis) {

        if (ind == word.size()) {
            return true;
        }
        int m = b.size();
        int n = b[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || vis[r][c] == 1 ||
            b[r][c] != word[ind]) {
            return false;
        }
        vis[r][c] = 1;
        int delr[] = {0, -1, 0, 1};
        int delc[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = r + delr[k];
            int nc = c + delc[k];
            if (dfs(nr, nc, ind + 1, b, word, vis)) {
                return true;
            }
        }
        vis[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};