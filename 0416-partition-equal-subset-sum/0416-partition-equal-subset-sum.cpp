class Solution {
public:
        bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
         vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
         for(int i=0;i<n;i++){
             dp[i][0]=true;
         }
         if(arr[0]<=sum){
         dp[0][arr[0]]=true;
         }
         for(int i=1;i<n;i++){
             for(int j=1;j<=sum;j++){
                 bool ntake=dp[i-1][j];
                 bool take=false;
                 if(j>=arr[i]){
                     take=dp[i-1][j-arr[i]];
                 }
                 dp[i][j]=take|ntake;
             }
         }
         return dp[n-1][sum];
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