class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pro = pro * nums[i];
            maxi = max(maxi, pro);
            if (pro < 0) {
                pro = 1;
            }
        }
        pro = 1;
        for (int j = n - 1; j >= 0; j--) {
            pro = pro * nums[j];
            maxi = max(maxi, pro);
            if (pro < 0) {
                pro = 1;
            }
        }
        return maxi;
    }
};