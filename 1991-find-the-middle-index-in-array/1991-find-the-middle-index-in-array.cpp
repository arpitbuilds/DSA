class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int total = 0;

        for (auto it : nums) {
            total += it;
        }

        int lsum = 0;

        for (int i = 0; i < nums.size(); i++) {

            total -= nums[i];

            if (lsum == total) {
                return i;
            }

            lsum += nums[i];
        }

        return -1;
    }
};