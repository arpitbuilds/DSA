class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool flag = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < m) {
                    if (grid[i][j] != grid[i + 1][j]) {
                        flag = false;
                        break;
                    }
                }
                if (j + 1 < n) {
                    if (grid[i][j] == grid[i][j + 1]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};