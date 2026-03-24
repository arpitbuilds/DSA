class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& v,
               vector<int>& freq, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == 0) {
                freq[i] = 1;
                v.push_back(nums[i]);
                solve(ind + 1, ans, v, freq, nums);
                v.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        vector<int> freq(n, 0);
        solve(0, ans, v, freq, nums);
        return ans;
    }
};