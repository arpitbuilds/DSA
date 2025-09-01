class Solution {
public:
    int climbStairs(int n) {
    vector<int>dp(n+1,-1);
      if(n<=2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
