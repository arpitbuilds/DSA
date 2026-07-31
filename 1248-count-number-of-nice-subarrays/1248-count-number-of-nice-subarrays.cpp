class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        int ans = 0;
        int cnt=0;
        int l = 0;
        int n = nums.size();
        int r = 0;
        while (r < n) {
            if (nums[r] % 2 == 1) {
                cnt++;
            }
            while (cnt > k) {
                if (nums[l] % 2 == 1) {
                    cnt--;
                }
                
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};