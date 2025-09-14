class Solution {
public:
    int solve(int idx, int target, vector<int>& nums, int n, vector<vector<int>>& dp) {
        // Base case: reached end of array
        if (idx == n) {
            return target == 0 ? 1 : 0;
        }

        // Return memoized result
        if (dp[idx][target] != -1) 
            return dp[idx][target];

        // Take current element if it does not exceed target
        int take = 0;
        if (target >= nums[idx]) 
            take = solve(idx + 1, target - nums[idx], nums, n, dp);

        // Skip current element
        int nottake = solve(idx + 1, target, nums, n, dp);

        // Store result in dp and return
        return dp[idx][target] = take + nottake;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, target, arr, n, dp);
    }
};
