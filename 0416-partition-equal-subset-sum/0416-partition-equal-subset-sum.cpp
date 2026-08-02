class Solution {
public:
  bool solve(int ind,vector<int>&arr,vector<vector<int>>&dp,int sum){
        
        if(sum==0){
            return true;
        }
        if(ind==0){
            return arr[ind]==sum;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool ntake=solve(ind-1,arr,dp,sum);
        bool take=false;
        if(arr[ind]<=sum){
            take=solve(ind-1,arr,dp,sum-arr[ind]);
        }
        return dp[ind][sum]=take | ntake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
       int n=arr.size();
       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       return solve(n-1,arr,dp,sum);
    }
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        if(tsum%2!=0){
            return false;
        }
        return isSubsetSum(nums,tsum/2);
    }
};