class Solution {
public:
    void solve(int ind, vector<int>& nums, int target,
               vector<int>& v, vector<vector<int>>& ans) {

        // BASE CONDITION (same style as comb sum 1)
        if (ind == nums.size()) {
            if (target == 0) {
                ans.push_back(v);
            }
            return;
        }

        // TAKE (only once → ind+1)
        if (nums[ind] <= target) {
            v.push_back(nums[ind]);
            solve(ind + 1, nums, target - nums[ind], v, ans);
            v.pop_back();
        }

        // SKIP duplicates
        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }

        // NOT TAKE
        solve(ind + 1, nums, target, v, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());   // 🔴 REQUIRED
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, candidates, target, v, ans);
        return ans;
    }
};
