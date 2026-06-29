class Solution {
public:
    void solve(int ind, vector<int>& v, vector<vector<int>>& ans,
               vector<int>& nums, vector<int>& freq) {
        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] != 1) {
                freq[i] = 1;
                v.push_back(nums[i]);
                solve(ind + 1, v, ans, nums, freq);
                freq[i] = 0;
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
                v.pop_back();

                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        vector<int> freq(nums.size(), 0);
        solve(0, v, ans, nums, freq);
        return ans;
    }
};