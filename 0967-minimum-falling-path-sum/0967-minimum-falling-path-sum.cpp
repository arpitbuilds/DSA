class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = dp[i - 1][j];

                int ld = 1e9;
                if (j > 0) {
                    ld = dp[i - 1][j - 1];
                }
                int rd = 1e9;
                if (j + 1 < n) {
                    rd = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min({up, ld, rd});
            }
        }
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int solve(int i,int j, vector<vector<int>>&dp, vector<vector<int>>&v,int
//     n){
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         if(i==0){
//             return v[i][j];
//         }
//          if (dp[i][j] != -1) return dp[i][j];
//         int up=solve(i-1,j,dp,v,n);
//         int ld=solve(i-1,j-1,dp,v,n);
//         int rd=solve(i-1,j+1,dp,v,n);
//         return dp[i][j]= v[i][j]+min({up,ld,rd});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         int ans=INT_MAX;
//         for(int j=0;j<n;j++){
//             ans=min(ans,solve(n-1,j,dp,matrix,n));
//         }
//         return ans;
//     }
// };