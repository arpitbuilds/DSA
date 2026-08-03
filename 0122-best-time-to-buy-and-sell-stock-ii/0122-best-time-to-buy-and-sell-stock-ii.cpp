class Solution {
public:
    int solve(int ind,int b,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size()){
            return 0;
        }
        int p=0;
        if(dp[ind][b]!=-1){
            return dp[ind][b];
        }
        if(b){
            p=max((-prices[ind]+solve(ind+1,0,n,prices,dp)),(0+solve(ind+1,b,n,prices,dp)));
        }
        else{
            p=max((prices[ind]+solve(ind+1,1,n,prices,dp)),(0+solve(ind+1,b,n,prices,dp)));
        }
        return  dp[ind][b]=p;
    }
    int maxProfit(vector<int>& prices) {
        int b=1;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,b,n,prices,dp);
    }
};