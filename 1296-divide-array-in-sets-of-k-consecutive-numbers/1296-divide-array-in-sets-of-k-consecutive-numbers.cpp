class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        if (nums.size() % k != 0) {
            return false;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mpp[nums[i]] > 0) {
                for (int j = 0; j <k; j++) {
                    int cc = nums[i] + j;
                    if (mpp[cc]==0) {
                        return false;
                    }
                    mpp[cc]--;
                }
            }
        }
        return true;
    }
};