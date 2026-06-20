class Solution {
public:
    void solve(int ind, vector<int>& v, vector<vector<int>>& ans,
               vector<int>& vis, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i=0; i < nums.size(); i++) {
            if (!vis[i]) {
                v.push_back(nums[i]);
                vis[i] = 1;
                solve(ind + 1, v, ans, vis, nums);
                vis[i] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        vector<int> vis(n, 0);
        solve(0, v, ans, vis, nums);
        return ans;
    }
};