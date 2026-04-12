class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int dis = st.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> st2;
            for (int j = i; j < n; j++) {
                st2.insert(nums[j]);
                if (st.size() == st2.size()) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};