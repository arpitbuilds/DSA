class Solution {
  public:
    int solve(int ind,vector<int>&arr,  vector<vector<int>>&dp,int t){
        if(ind==0){
            if(arr[0]==0 && t==0 ){
                return 2;
            }
            if(t==0 || t==arr[0]){
                return 1;
            }
            return 0;
        }
        if(dp[ind][t]!=-1){
            return dp[ind][t];
        }
        int take=0;
        if(t>=arr[ind]){
        take=solve(ind-1,arr,dp,t-arr[ind]);
        }
        int ntake=solve(ind-1,arr,dp,t);
        return dp[ind][t]=take+ntake;
        
    }
    int find(vector<int>&arr,int t){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return solve(n-1,arr,dp,t);
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int t=0;
        for(auto it : arr){
            t+=it;
        }
        if((t-diff)<0 || ((t-diff)%2)!=0){
            return 0;
        }
        return find(arr,(t-diff)/2);
    }
};