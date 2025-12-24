class Solution {
public:
    int solve(int ind, int n,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int ntake=0+solve(ind+1,n,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+solve(ind+1,n,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n,-1,nums,dp);
    }
};