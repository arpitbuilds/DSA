class Solution {
public:
    // int solve(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind==0){
    //         return nums[ind];
    //     }
    //     if(ind<0){
    //         return 0;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     int pick=solve(ind-2,nums,dp)+nums[ind];
    //     int npick=0+solve(ind-1,nums,dp);
    //     return dp[ind]=max(pick,npick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
    //    vector<int>dp(n,0); 
        int prev=nums[0];
        int prev2=0;
        for(int ind=1;ind<n;ind++){
            int pick=nums[ind];
            if(ind>1){
                pick+=prev2;
            }
            int npick=0+prev;
            int curi=max(pick,npick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};