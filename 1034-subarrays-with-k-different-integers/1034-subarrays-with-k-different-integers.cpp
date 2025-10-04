class Solution {
public:
    int help(vector<int>& s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int ans=0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[s[r]]++;
            while (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};