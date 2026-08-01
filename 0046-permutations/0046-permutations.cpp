class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& v, vector<int>& vis, vector<int>& nums) {

        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                v.push_back(nums[i]);
                vis[i] = 1;
                solve(ind + 1, v, vis, nums);
                v.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<int> vis(n, 0);
        solve(0, v, vis, nums);
        return ans;
    }
};