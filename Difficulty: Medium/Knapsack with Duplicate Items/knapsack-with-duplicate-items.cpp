// User function Template for C++

class Solution {
  public:
    int solve(int ind,vector<int>&val,vector<int>&wt,int W, vector<vector<int>>&dp){
        if(ind==0){
            return (W/wt[ind])*val[ind];
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        int ntake=0+solve(ind-1,val,wt,W,dp);
        int take=INT_MIN;
        if(wt[ind]<=W){
            take=val[ind]+solve(ind,val,wt,W-wt[ind],dp);
        }
        return dp[ind][W]=max(take,ntake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        
        int ans=solve(n-1,val,wt,capacity,dp);
        return ans;
    }
};