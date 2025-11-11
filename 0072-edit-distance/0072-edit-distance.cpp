class Solution {
public:
    int solve(int x,int y,string &s,string &w,vector<vector<int>>&dp){
        if(x<0){
            return y+1;
        }
        if(y<0){
            return x+1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(s[x]==w[y]){
            return dp[x][y]=0+solve(x-1,y-1,s,w,dp);
        }
        int inser=1+solve(x,y-1,s,w,dp);
        int del=1+solve(x-1,y,s,w,dp);
        int rep=1+solve(x-1,y-1,s,w,dp);
        return dp[x][y]=min({inser,del,rep});
    }
    int minDistance(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,w1,w2,dp);
    }
};