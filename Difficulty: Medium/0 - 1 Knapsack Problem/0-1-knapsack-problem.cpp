class Solution {
  public:
    int solve(int ind,vector<int>&wt,vector<int>&val,int W,vector<vector<int>>&dp){
        
        if(ind==0){
            if(wt[ind]<=W){
                return val[ind];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        int take=0;
        if(wt[ind]<=W){
            take=val[ind]+solve(ind-1,wt,val,W-wt[ind],dp);
        }
        int ntake=0+solve(ind-1,wt,val,W,dp);
        return dp[ind][W]=max(take,ntake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,wt,val,W,dp);
    }
};