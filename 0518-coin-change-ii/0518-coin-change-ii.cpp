class Solution {
public:
    // int solve(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(amount%coins[0]==0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[ind][amount]!=-1){
    //         return dp[ind][amount];
    //     }
    //     int ntake=solve(ind-1,amount,coins,dp);
    //     int take=0;
    //     if(coins[ind]<=amount){
    //         take=solve(ind,amount-coins[ind],coins,dp);
    //     }
    //   return dp[ind][amount]=take+ntake;
    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if (i% coins[0] == 0) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
            long long ntake=prev[j];
            long long take=0;
            if(coins[i]<=j){
                take=cur[j-coins[i]];
            }
            cur[j]=take+ntake;
            }
            prev=cur;
        }
        return prev[amount];
    }
};