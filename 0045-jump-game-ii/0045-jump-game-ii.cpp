class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        int far = 0;
        int jump = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + nums[i]);
            if (i == c) {
                jump++;
                c = far;
            }
        }
        return jump;
    }
};