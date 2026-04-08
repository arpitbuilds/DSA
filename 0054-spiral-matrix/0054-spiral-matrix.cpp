class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int tot = m * n;
        int cnt = 0;
        int sr = 0;
        int sc = 0;
        int er = m - 1;
        int ec = n - 1;
        while (cnt < tot) {
            for (int i = sc; i <= ec && cnt < tot; i++) {
                ans.push_back(mat[sr][i]);
                cnt++;
            }
            sr++;
            for (int i = sr; i <= er && cnt < tot; i++) {
                ans.push_back(mat[i][ec]);
                cnt++;
            }
            ec--;
            for (int i = ec; i >= sc && cnt < tot; i--) {
                ans.push_back(mat[er][i]);
                cnt++;
            }
            er--;
            for (int i = er; i >= sr && cnt < tot; i--) {
                ans.push_back(mat[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans;
    }
};