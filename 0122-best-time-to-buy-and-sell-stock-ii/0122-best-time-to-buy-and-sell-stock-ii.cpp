class Solution {
public:
    // int solve(int ind ,int b,vector<int>&p,vector<vector<int>>&dp,int n){
    //     if(ind==n){
    //         return 0;
    //     }
    //     if(dp[ind][b]!=-1){
    //         return dp[ind][b];
    //     }
    //     int profit=0;
    //     if(b){
    //     profit=max((-p[ind]+solve(ind+1,0,p,dp,n)),(0+solve(ind+1,1,p,dp,n)));
    //     }
    //     else{
    //         profit=max((p[ind]+solve(ind+1,1,p,dp,n)),(0+solve(ind+1,0,p,dp,n)));
    //     }
    //     return dp[ind][b]=profit;
    // }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // return solve(0,1,prices,dp,n);
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                  int profit=0;
         if(b){
        profit=max((-p[i]+dp[i+1][0]),(0+dp[i+1][1]));
        }
        else{
            profit=max((p[i]+dp[i+1][1]),(0+dp[i+1][0]));
        }
         dp[i][b]=profit;
            }
        }
        return dp[0][1];
    }
};