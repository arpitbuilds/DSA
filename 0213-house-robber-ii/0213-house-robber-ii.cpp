class Solution {
public:
      int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0) {
            return 0;
        }
        if (ind == 0) {
            return nums[ind];
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int op1 = nums[ind] + solve(ind - 2, nums, dp);
        int op2 = 0 + solve(ind - 1, nums, dp);
        return dp[ind] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>temp1(nums.begin(),nums.end()-1);
        vector<int> dp1(n-1, -1);
        int ans1=solve(n-2,temp1,dp1);
        vector<int>temp2(nums.begin()+1,nums.end());
        vector<int>dp2(n-1,-1);
        int ans2=solve(n-2,temp2,dp2);
        return max(ans1,ans2);
         
    }
};