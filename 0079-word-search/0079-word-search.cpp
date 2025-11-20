class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx,
             int m, int n) {
        if (idx == word.size()) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        bool op1 = dfs(board, word, i + 1, j, idx + 1, m, n);
        bool op2 = dfs(board, word, i - 1, j, idx + 1, m, n);
        bool op3 = dfs(board, word, i, j + 1, idx + 1, m, n);
        bool op4 = dfs(board, word, i, j - 1, idx + 1, m, n);

        board[i][j] = temp;
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};