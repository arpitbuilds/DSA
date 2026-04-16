class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int maxi=INT_MIN;
        unordered_set<int> st;
        while (r < n) {
            while (st.find(nums[r]) != st.end()) {
                st.erase(nums[l]);
                sum = sum - nums[l];
                l++;
            }
            sum += nums[r];
            maxi=max(maxi,sum);
            st.insert(nums[r]);
            r++;
        }
        return maxi;
    }
};