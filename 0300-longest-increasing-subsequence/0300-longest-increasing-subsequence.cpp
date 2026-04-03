class Solution {
public:
    int solve(int ind,int prev,vector<vector<int>>&dp,vector<int>&nums){
        int n=nums.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int ntake=0+solve(ind+1,prev,dp,nums);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+solve(ind+1,ind,dp,nums);
        }
        return dp[ind][prev+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>>dp(n,vector<int>(n+1,prev));
        return solve(0,prev,dp,nums);
    }
};