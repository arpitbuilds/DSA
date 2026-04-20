class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int n = nums.size();
        int cnt = 0;
        long long ans=0;
        while (r < n) {
            if (nums[r] == maxi) {
                cnt++;
            }
            while(cnt >= k) {
                ans += n - r;
                if (nums[l] == maxi) {
                    cnt--;
                }

                l++;
            }

            r++;
        }
        return ans;
    }
};