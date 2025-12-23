class Solution {
public:
    int solve(string w ,string t , int i,int j,vector<vector<int>>&dp){
        if(i<0){
        return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(w[i]==t[j]){
            return dp[i][j]=0+solve(w,t,i-1,j-1,dp);
        }
        int op1=1+solve(w,t,i,j-1,dp);
        int op2=1+solve(w,t,i-1,j,dp);
        int op3=1+solve(w,t,i-1,j-1,dp);
        return dp[i][j]=min({op1,op2,op3});
    }
    int minDistance(string w, string t) {
        int m=w.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(w,t,m,n,dp);
    }
};