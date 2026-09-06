class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0;
        int k=2;
        int maxi=INT_MIN;
        int r = 0;
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};