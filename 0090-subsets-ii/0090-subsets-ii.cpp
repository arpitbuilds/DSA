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
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }
        solve(ind + 1, v, ans, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
         solve(0, v,ans, nums);
        return ans;
    }
};