class Solution {
public:
    // int solve(int ind,vector<int>&coins,int amt,  vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(amt%coins[ind]==0){
    //             return amt/coins[ind];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }
    //     if(dp[ind][amt]!=-1){
    //         return dp[ind][amt];
    //     }
    //     int ntake=solve(ind-1,coins,amt,dp);
    //     int take=1e9;
    //     if(amt>=coins[ind]){
    //         take=1+solve(ind,coins,amt-coins[ind],dp);
    //     }
    //     return dp[ind][amt]=min(take,ntake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans=solve(n-1,coins,amount,dp);
        // return ans>=1e9?-1:ans;
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0){
                dp[0][a]= a/coins[0];
            }
            else{
                dp[0][a]= 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
        int ntake=dp[i-1][a];
        int take=1e9;
        if(a>=coins[i]){
            take=1+dp[i][a-coins[i]];
        }
        dp[i][a]=min(take,ntake);
            }
        }
      int ans = dp[n-1][amount];
return ans >= 1e9 ? -1 : ans;
    }
};