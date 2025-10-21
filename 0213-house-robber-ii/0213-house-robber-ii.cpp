class Solution {
public:
    int solve(int l,int r ,vector<int>&nums){
     int prev2=0;
     int prev=nums[l];
     for(int i=l+1;i<=r;i++){
        int take=nums[i];
        if(i>l+1){
            take+=prev2;
        }
        int ntake=0+prev;
        int curi=max(take,ntake);
        prev2=prev;
        prev=curi;
     }
     return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int case1=solve(0,n-2,nums);
        int case2=solve(1,n-1,nums);
        return max(case1,case2);
    }
};