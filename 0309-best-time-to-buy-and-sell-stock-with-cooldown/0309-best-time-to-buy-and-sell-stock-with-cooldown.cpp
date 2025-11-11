class Solution {
public:
    int solve(int ind,int b,vector<int>&p,vector<vector<int>>&dp){
        int n=p.size();
        if(ind>=n){
            return 0;
        }
        int pf=0;
        if(dp[ind][b]!=-1){
            return dp[ind][b];
        }
        if(b){
            pf=max((-p[ind]+solve(ind+1,0,p,dp)),(0+solve(ind+1,1,p,dp)));
        }
        else{
            pf=max((p[ind]+solve(ind+2,1,p,dp)),(0+solve(ind+1,0,p,dp)));
        }
        return dp[ind][b]=pf;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};