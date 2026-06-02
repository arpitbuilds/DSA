class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto it : nums1) {
            cnt[it]++;
        }
        for (auto it : nums2) {
            if (cnt[it] > 0) {
                ans.push_back(it);
                cnt[it]--;
            }
        }
        return ans;
    }
};