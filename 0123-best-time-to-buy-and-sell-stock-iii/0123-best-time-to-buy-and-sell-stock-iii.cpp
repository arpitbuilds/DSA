class Solution {
public:
    int solve(int ind,int n,int b,int c,vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || c==0){
            return 0;
        }
        int p=0;
        if(dp[ind][b][c]!=-1){
            return dp[ind][b][c];
        }
        if(b){
            p=max((-prices[ind]+solve(ind+1,n,0,c,prices,dp)),(0+solve(ind+1,n,b,c,prices,dp)));
        }
        else{
            p=max((prices[ind]+solve(ind+1,n,1,c-1,prices,dp)),(0+solve(ind+1,n,b,c,prices,dp)));
        }
        return  dp[ind][b][c]=p;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int b=1;
        int c=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,n,b,c,p,dp);

        
    }
};