class Solution {
public:
    // bool solve(vector<int>&nums,vector<int>&dp,int n,int ind){
    //     if(ind==n-1){
    //         return true;
    //     }
    //  for(int i=1;i<=nums[ind];i++){
    //     if(solve(nums,dp,n,ind+i)){
    //         return true;
    //     }
    //  }
    //  return false;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);
        dp[0]=true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==true && j+nums[j]>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};