class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;   // local, no need to clear
        int n = nums.size();
        if (n < 3) return {};

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate n1

            int target = -nums[i];
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) l++; // skip dup n2
                    while (l < r && nums[r] == nums[r - 1]) r--; // skip dup n3

                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};
