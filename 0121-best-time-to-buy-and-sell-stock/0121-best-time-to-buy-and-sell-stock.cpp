class Solution {
public:
    int maxProfit(vector<int>& p) {
        int maxi = 0;
        int n = p.size();
        int mini = p[0];
        for (int i = 1; i < n; i++) {
            int profit = p[i] - mini;
            mini=min(mini,p[i]);
            maxi = max(maxi, profit);
        }
        return maxi;
    }
};