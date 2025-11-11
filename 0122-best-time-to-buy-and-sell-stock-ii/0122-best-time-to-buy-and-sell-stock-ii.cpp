class Solution {
public:
    int solve(int ind ,int b,vector<int>&p,vector<vector<int>>&dp,int n){
        if(ind==n){
            return 0;
        }
        if(dp[ind][b]!=-1){
            return dp[ind][b];
        }
        int profit=0;
        if(b){
        profit=max((-p[ind]+solve(ind+1,0,p,dp,n)),(0+solve(ind+1,1,p,dp,n)));
        }
        else{
            profit=max((p[ind]+solve(ind+1,1,p,dp,n)),(0+solve(ind+1,0,p,dp,n)));
        }
        return dp[ind][b]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,n);
    }
};