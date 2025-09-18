class Solution {
public:
//   int solve(int ind, int buy, vector<int>& prices,  vector<vector<int>>
//     &dp,int fee) {
//         int n = prices.size();
//         if (ind == n) {
//             return 0;
//         }
//         if (dp[ind][buy] != -1) {
//             return dp[ind][buy];
//         }
//         int profit = 0;
//         if (buy) {
//             profit = max(-prices[ind] -fee + solve(ind + 1, 0, prices,dp,fee),
//                          0 + solve(ind + 1, 1, prices,dp,fee));
//         } else {
//             profit = max(prices[ind] + solve(ind + 1, 1, prices,dp,fee),
//                          0 + solve(ind + 1, 0, prices,dp,fee));
//         }
//         return dp[ind][buy] = profit;
//     }
    int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int b = 0; b <= 1; b++) {
                int profit = 0;
                if (b) {
                    profit =
                        max(-prices[ind]-fee + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                } else {
                    profit =
                        max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
                }
                dp[ind][b] = profit;
            }
        }
        return dp[0][1];
    }
};