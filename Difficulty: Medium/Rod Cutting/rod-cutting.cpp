// User function Template for C++

class Solution {
  public:
      int solve(int ind,int N,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==0){
            return N*prices[0]; 
        }
        if(dp[ind][N]!=-1){
            return dp[ind][N];
        }
        int ntake=0+solve(ind-1,N,prices,dp);
        int take=INT_MIN;
        int rodl=ind+1;
        if(rodl<=N){
            take=prices[ind]+solve(ind,N-rodl,prices,dp);
        }
     return dp[ind][N]=max(take,ntake);
    }
    int cutRod(vector<int> &price) {
        // code here
      int n=price.size();
     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
     return solve(n-1,n,price,dp);
    }
};