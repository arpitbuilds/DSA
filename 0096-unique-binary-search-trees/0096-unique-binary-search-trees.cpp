class Solution {
public:
    vector<int> dp;

    int numTrees(int n) {
        if (dp.size()==0)
            dp.assign(n+1, -1);   // initialize once

        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];

        int ways = 0;
        for (int i = 1; i <= n; i++) {
            ways += numTrees(i-1) * numTrees(n-i);
        }

        return dp[n] = ways;
    }
};
