class Solution {
public:
    int solve(int ind,int k,int n,int c,vector<int>&p,vector<vector<vector<int>>>&dp){
        if(ind==n || k==0){
            return 0;
        }
        if(dp[ind][c][k]!=-1){
            return dp[ind][c][k];
        }
        int pr=0;
        if(c){
            pr=max((-p[ind]+solve(ind+1,k,n,c-1,p,dp)),(0+solve(ind+1,k,n,c,p,dp)));
        }
        else{
            pr=max((p[ind]+solve(ind+1,k-1,n,c+1,p,dp)),(0+solve(ind+1,k,n,c,p,dp)));
        }
        return dp[ind][c][k]=pr;
    }
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        int c=1;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,k,n,c,p,dp);
    }
};