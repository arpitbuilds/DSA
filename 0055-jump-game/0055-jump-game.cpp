class Solution {
public:
    bool solve(vector<int>&nums,int n,int ind,vector<int>&dp){
        if(ind==n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i=1;i<=nums[ind];i++){
            if(solve(nums,n,ind+i,dp)==true){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n,0,dp);
    }
};