class Solution {
  public:
    int solve(int ind,int sum,vector<int>&arr, vector<vector<int>>&dp){
        if(ind==0){
            if(arr[0]==0 && sum==0){
                return 2;
            }
            else if(arr[0] ==sum || sum==0){
                return 1;
            }
            return 0;
        }
         if (dp[ind][sum] != -1) return dp[ind][sum];
        int ntake=solve(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum){
        take=solve(ind-1,sum-arr[ind],arr,dp);
        }
        return dp[ind][sum]=take+ntake;
    }
    int find(vector<int>&arr,int target){
         int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int tsum=0;
        for(auto it:arr){
            tsum+=it;
        }
        if(tsum-d<0 || (tsum-d)%2!=0){
            return 0;
        }
        return find(arr,(tsum-d)/2);
        
        
    }
};