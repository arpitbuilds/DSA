class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto it : nums) {
            st.insert(it);
        }
        int maxi=0;
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
            int cur = it;
            int  cnt = 1;
                while (st.find(cur + 1) != st.end()) {
                    cur++;
                    cnt++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};