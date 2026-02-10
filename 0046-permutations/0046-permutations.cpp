class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& ds, vector<int>& freq,
               int n, vector<int>& nums) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (freq[i]==0) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(ans, ds, freq, n, nums);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> freq(n, 0);
        solve(ans, ds, freq, n, nums);
        return ans;
    }
};