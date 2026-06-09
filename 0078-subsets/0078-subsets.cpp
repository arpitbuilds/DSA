class Solution {
public:
    void solve(int ind,int n,vector<int>&v,vector<vector<int>>&ans,vector<int>nums){
        if(ind==n){
            ans.push_back(v);
            return ;
        }
        v.push_back(nums[ind]);
        solve(ind+1,n,v,ans,nums);
        v.pop_back();
        solve(ind+1,n,v,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        vector<vector<int>>ans;
        solve(0,n,v,ans,nums);
        return ans;
    }
};