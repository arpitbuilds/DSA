class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int mark = -1;
        int swapp = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                mark = i - 1;
                break;
            }
        }
        if (mark != -1) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums[j] > nums[mark]) {
                    swapp = j;
                    break;
                }
            }
            swap(nums[swapp], nums[mark]);
        }
        reverse(nums.begin() + 1 + mark, nums.end());
    }
};