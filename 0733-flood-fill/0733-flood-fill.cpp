class Solution {
public:
    void solve(int m, int n, int sr, int sc, int inic, int color,
               vector<vector<int>>& ans, vector<vector<int>>& img) {
        ans[sr][sc] = color;
        int delr[] = {-1, 0, +1, -0};
        int delc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delr[i];
            int ncol = sc + delc[i];

            if (nrow >= 0 && nrow < m && ncol < n && ncol >= 0 &&
                img[nrow][ncol] == inic && ans[nrow][ncol] != color) {
                solve(m, n, nrow, ncol, inic, color, ans, img);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans = image;
        int inic = image[sr][sc];
        solve(m, n, sr, sc, inic, color, ans, image);
        return ans;
    }
};