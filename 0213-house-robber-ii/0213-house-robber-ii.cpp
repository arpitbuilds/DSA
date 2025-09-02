class Solution {
public:
    int solve(vector<int>&nums,int l,int r){
        int prev=nums[l];
        int prev2=0;
        for(int i=l+1;i<=r;i++){
            int take=nums[i];
            if(i>l+1){
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
        int n=nums.size();
         if (n == 1) return nums[0];         
        if (n == 2) return max(nums[0], nums[1]);
        int case1=solve(nums,0,n-2);
        int case2=solve(nums,1,n-1);
        return max(case1,case2);
    }
};