class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int lsum = 0;
        int rsum = 0;
        for (auto it : nums) {
            rsum += it;
        }
        for (int i = 0; i < n; i++) {
            rsum -= nums[i];
            if (lsum == rsum) {
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};