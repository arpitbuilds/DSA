class Solution {
public:
    int mini = INT_MAX;
    int reve(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (mpp.count(nums[i])) {
                mini = min(mini, abs(i - mpp[nums[i]]));
            }
             mpp[reve(nums[i])] = i;
        }
        if (mini == INT_MAX) {
            return -1;
        } else {
            return mini;
        }
    }
};