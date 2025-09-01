class Solution {
public:
    int solve(vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int ntake=prev;
            int curi=max(take,ntake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};