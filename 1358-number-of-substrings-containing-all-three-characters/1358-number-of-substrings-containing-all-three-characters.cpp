class Solution {
public:
    int numberOfSubstrings(string nums) {
        int n = nums.size();
        unordered_map<char, int> mpp;
        int l = 0;
        int r = 0;
        int cnt = 0;
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp['a'] > 0 && mpp['b'] && mpp['c'] > 0) {
                cnt += (n - r);
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};