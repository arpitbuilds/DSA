class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate first elements

            int target = -nums[i];
            unordered_map<int,int> mpp;

            for (int j = i+1; j < n; j++) {
                int rem = target - nums[j];
                if (mpp.find(rem) != mpp.end()) {
                    ans.push_back({nums[i], rem, nums[j]});

                    // skip duplicates for nums[j]
                    while (j+1 < n && nums[j] == nums[j+1]) j++;
                }
                mpp[nums[j]] = j;
            }
        }
        return ans;
    }
};
