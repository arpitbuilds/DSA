class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int ans = 0;
        int n = nums.size();

        while (right < n) {
            // expand window
            freq[nums[right]]++;

            // shrink if invalid
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // count subarrays ending at right
            ans += (right - left + 1);

            right++;
        }

        return ans;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int K = st.size();

        return atMostK(nums, K) - atMostK(nums, K - 1);
    }
};