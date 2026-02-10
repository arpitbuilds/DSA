class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& ans, vector<int>& freq) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (freq[i] == 0) {

                // TAKE
                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();

                // 🔥 DUPLICATE SKIP (exactly like subsets / comb sum 2)
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // 🔴 MUST
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        solve(nums, ds, ans, freq);
        return ans;
    }
};
