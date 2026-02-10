class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&nums){
        if(ind>=nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,ans,v,nums);
        v.pop_back();
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }
        solve(ind+1,ans,v,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int ind=0;
        sort(nums.begin(), nums.end());

        solve(ind,ans,v,nums);
        return ans;
    }
};