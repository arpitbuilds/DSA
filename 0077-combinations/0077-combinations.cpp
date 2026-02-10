class Solution {
public:
    void solve(int i, int n, int k, vector<int>& v, vector<vector<int>>& ans) {
        if (i > n) {
            if (v.size() == k) {
                ans.push_back(v);
            }
            return;
        }
        v.push_back(i);
        solve(i + 1, n, k, v, ans);
        v.pop_back();
        solve(i + 1, n, k, v, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, n, k, v, ans);
        return ans;
    }
};