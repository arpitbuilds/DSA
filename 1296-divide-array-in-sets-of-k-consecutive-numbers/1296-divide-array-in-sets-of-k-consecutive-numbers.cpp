class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        if (n % k != 0) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (mpp[nums[i]] == 0) {
                continue;
            }
            for (int j = 0; j < k; j++) {
                int cc = nums[i] + j;
                if (mpp[cc] == 0) {
                    return false;
                }
                mpp[cc]--;
            }
        }
        return true;
    }
};