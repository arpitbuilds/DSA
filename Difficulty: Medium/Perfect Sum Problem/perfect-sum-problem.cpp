class Solution {
  public:
   int solve(int idx,int target,vector<int>&nums,int n,vector<vector<int>>&dp){
//base case
if (idx == 0) {
    if (target == 0 && nums[0] == 0) return 2;  // two ways: include or exclude
    if (target == 0 || target == nums[0]) return 1;
    return 0;
}

if(dp[idx][target]!=-1) return dp[idx][target];

int take=0;
if(target>=nums[idx]) take=solve(idx-1,target-nums[idx],nums,n,dp);
int nottake=solve(idx-1,target,nums,n,dp);

return dp[idx][target]=take+nottake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
         int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,n,dp);
    }
};