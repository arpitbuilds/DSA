class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&v,int ind,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ans,v,ind+1,nums);
        v.pop_back();
        solve(ans,v,ind+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int ind=0;
        solve(ans,v,ind,nums);
        return ans;
    }
};