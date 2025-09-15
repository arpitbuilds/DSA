class Solution {
  public:
    int solve(int ind ,int mw,vector<int> &wt,vector<int> &val,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=mw){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][mw]!=-1){
            return dp[ind][mw];
        }
        int ntake=0 + solve(ind-1,mw,wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=mw){
            take=val[ind]+solve(ind-1,mw-wt[ind],wt,val,dp);
        }
        return dp[ind][mw]= max(ntake,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,wt,val,dp);
        
    }
};