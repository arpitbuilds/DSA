class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int cur = nums[i % n];
            while (!st.empty() && st.top() <= cur) {
                st.pop();
            }
            if (i < n) {
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(cur);
        }
        return res;
    }
};