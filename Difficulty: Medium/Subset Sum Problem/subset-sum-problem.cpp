class Solution {
  public: 
    bool solve(int ind,int target,vector<int>&arr, vector<vector<int>>&dp){
       if(target==0){
           return true;
       }
       if(ind==0){
           return arr[ind]==target;
       }
       if(dp[ind][target]!=-1){
           return dp[ind][target];
       }
       int ntake=solve(ind-1,target,arr,dp);
       int take=false;
       if(target>=arr[ind]){
       take=solve(ind-1,target-arr[ind],arr,dp);
       }
       return dp[ind][target]=take|ntake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(sum+1,-1));
          return solve(n-1,sum,arr,dp);
    }
};