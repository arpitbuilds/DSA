class Solution {
public:
     int solve(int ind, vector<vector<int>>&dp,vector<int>&coins,int amount){       if(ind==0){
        if(amount%coins[0]==0){
            return amount/coins[ind];
        }
        else{
            return 1e9;
        }

     }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int ntake=0+solve(ind-1,dp,coins,amount);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+solve(ind,dp,coins,amount-coins[ind]);
        }
        return dp[ind][amount]=min(take,ntake);
     }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,dp,coins,amount);
        return (ans>=1e9)?-1:ans;
    }
};