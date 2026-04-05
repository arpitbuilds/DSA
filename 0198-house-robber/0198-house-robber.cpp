class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){

        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[ind];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int op1=nums[ind]+solve(ind-2,nums,dp);
        int op2=0+solve(ind-1,nums,dp);
        return dp[ind]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};