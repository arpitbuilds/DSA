class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>> &ans,
               vector<int>& v) {
        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind + 1, nums, ans, v);
        v.pop_back();
        solve(ind + 1, nums, ans, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, nums, ans, v);
        return ans;
    }
};