class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mini = a[0];
        int p = 0;
        int cost=0;
        for (int i = 0; i < n; i++) {
            cost=a[i]-mini;
            p=max(p,cost);
            mini = min(mini, a[i]);
        }
        return p;
    }
};