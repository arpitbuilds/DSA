class Solution {
public:
    void solve(int ind, vector<int>& v, vector<vector<int>>& ans,
               vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind + 1, v, ans, nums);
        v.pop_back();
        solve(ind + 1, v, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, v, ans, nums);
        return ans;
    }
};