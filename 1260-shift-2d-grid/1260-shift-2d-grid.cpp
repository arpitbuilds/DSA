class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res = grid;
        while(k){
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    if(i == 0 and j == 0)
                        res[i][j] = grid[m - 1][n - 1];
                    else{
                        res[i][j] = grid[i - (j == 0)][j - 1 + (j == 0) * n];
                    }
                }
            }
            grid = res;
            k--;
        }
        return res;
    }
};