class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> ls(n, 0);
        int lsum = 0;
        for (int i = 0; i < n; i++) {
            ls[i] = lsum;
            lsum += nums[i];
        }

        vector<int> rs(n, 0);
        int rsum = 0;
        for (int i = n - 1; i >= 0; i--) {
            rs[i] = rsum;
            rsum += nums[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = abs(ls[i] - rs[i]);
        }

        return ans;
    }
};