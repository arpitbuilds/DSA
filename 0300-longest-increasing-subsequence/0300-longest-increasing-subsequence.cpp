class Solution {
public:
    int solve(int i, int n, int p, vector<int>& v, vector<vector<int>>& dp) {
        if (i ==n) return 0; // prevent overflow
        if (dp[i][p + 1] != -1) return dp[i][p + 1];

        int notTake = solve(i + 1, n, p, v, dp);
        int take = 0;
        if (p == -1 || v[i] > v[p]) {
            take = 1 + solve(i + 1, n, i, v, dp);
        }

        return dp[i][p + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n + 1, -1));
        return solve(0, n, -1, nums, dp);
    }
};
