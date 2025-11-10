// User function Template for C++

class Solution {
  public:
    int solve(int ind,int n,vector<vector<int>>&dp,vector<int>&p){
        if(ind==0){
            return n*p[0];
        }
        if(dp[ind][n]!=-1){
            return dp[ind][n];
        }
        int ntake=0+solve(ind-1,n,dp,p);
        int take=INT_MIN;
        int rodl=ind+1;
        if(rodl<=n){
            take=p[ind]+solve(ind,n-rodl,dp,p);
        }
        return dp[ind][n]=max(take,ntake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,dp,price);
    }
};