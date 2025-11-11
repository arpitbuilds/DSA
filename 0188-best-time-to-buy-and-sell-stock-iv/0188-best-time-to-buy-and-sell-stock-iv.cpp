class Solution {
public:
  int solve(int ind, int b, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (ind == n || cap == 0) {
            return 0;
        }
        if (dp[ind][b][cap] != -1) {
            return dp[ind][b][cap];
        }
        int profit = 0;
        if (b) {
            profit = max(-prices[ind] + solve(ind + 1, 0, cap, prices, dp),
                         0 + solve(ind + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp),
                         0 + solve(ind + 1, 0, cap, prices, dp));
        }
        return dp[ind][b][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};