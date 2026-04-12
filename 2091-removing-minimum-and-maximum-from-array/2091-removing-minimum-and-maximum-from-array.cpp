class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mi = *min_element(nums.begin(), nums.end());
        int ma = *max_element(nums.begin(), nums.end());

        int mini = find(nums.begin(), nums.end(), mi) - nums.begin();
        int maxi = find(nums.begin(), nums.end(), ma) - nums.begin();

        int f = max(mini, maxi) + 1;
        int b = n - min(maxi, mini);
        int fb = (min(maxi, mini) + 1) + (n - max(maxi, mini));

        return min({f, b, fb});
    }
};