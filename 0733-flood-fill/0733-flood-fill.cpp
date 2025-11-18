class Solution {
public:
    void solve(vector<vector<int>>& img, vector<vector<int>>& ans, int sr,
               int sc, int color, int inic) {
                int m=img.size();
                int n=img[0].size();
        ans[sr][sc] = color;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delr[i];
            int ncol = sc + delc[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                img[nrow][ncol] == inic && ans[nrow][ncol] != color) {
                solve(img, ans, nrow, ncol, color, inic);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int inic = image[sr][sc];
        solve(image, ans, sr, sc, color, inic);
        return ans;
    }
};