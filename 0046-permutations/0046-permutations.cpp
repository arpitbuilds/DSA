class Solution {
public:
    void solve(int ind,vector<int>&vis,vector<vector<int>>&ans,vector<int>&nums,vector<int>&v){
        if(ind==nums.size()){
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                v.push_back(nums[i]);
                solve(ind+1,vis,ans,nums,v);
                vis[i]=0;
                v.pop_back();
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,vis,ans,nums,v);
        return ans;
    }
};