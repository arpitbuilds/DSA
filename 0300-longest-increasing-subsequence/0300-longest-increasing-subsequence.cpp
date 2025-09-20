class Solution {
public:
//    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
//         int n = nums.size();
//         if (ind == n) {
//             return 0;
//         }
//         if (dp[ind][prev + 1] != -1) {
//             return dp[ind][prev + 1];
//         }
//         int ntake = 0 + solve(ind + 1, prev, nums, dp);
//         int take=0;
//         if (prev == -1 || nums[ind] > nums[prev]) {
//          take =  1 + solve(ind + 1, ind, nums, dp);
//         }x
//         return dp[ind][prev + 1] = max(take,ntake);
//     }
    int lengthOfLIS(vector<int>& arr) {
        // int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);
        int n=arr.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev] <arr[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};