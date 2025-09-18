class Solution {
public:
    // int solve(int ind, int b, int cap, vector<int>& prices,
    //           vector<vector<vector<int>>>& dp) {
    //     int n = prices.size();
    //     if (ind == n || cap == 0) {
    //         return 0;
    //     }
    //     if (dp[ind][b][cap] != -1) {
    //         return dp[ind][b][cap];
    //     }
    //     int profit = 0;
    //     if (b) {
    //         profit = max(-prices[ind] + solve(ind + 1, 0, cap, prices, dp),
    //                      0 + solve(ind + 1, 1, cap, prices, dp));
    //     } else {
    //         profit = max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp),
    //                      0 + solve(ind + 1, 0, cap, prices, dp));
    //     }
    //     return dp[ind][b][cap] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        cur[buy][cap] =
                            max(-prices[ind] + after[0][cap],
                                0 + after[1][cap]);
                    } else {
                        cur[buy][cap] =
                            max(prices[ind] + after[1][cap - 1],
                                0 + after[0][cap]);
                    }

                }
            }
            after=cur;
        }

        return after[1][2];
    }
};
