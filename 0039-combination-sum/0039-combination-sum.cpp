class Solution {
public:
    void solve(int ind, vector<int>& v, vector<vector<int>>& ans,
               vector<int>& c, int t) {
        if (ind == c.size()) {
            if (t == 0) {
                ans.push_back(v);
            }
              return;
        }
        if (c[ind] <= t) {
            v.push_back(c[ind]);
            solve(ind, v, ans, c, t - c[ind]);
            v.pop_back();
        }
        solve(ind + 1, v, ans, c, t);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(0, v, ans, c, t);
        return ans;
    }
};