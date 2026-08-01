class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&v,vector<int>&vis){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                v.push_back(nums[i]);
                solve(ind+1,nums,ans,v,vis);
                vis[i]=0;
                while(i+1<nums.size() && nums[i]==nums[i+1]){
                    i++;
                }
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>vis(nums.size(),0);
        solve(0,nums,ans,v,vis);
        return ans;
    }
};