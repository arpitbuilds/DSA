class Solution {
public:
    int ans(vector<int>& nums, int goal) {
       int l=0;
       int r=0;
       int sum=0;
       int maxi=0;
       int n=nums.size();
       if(goal<0){
        return 0;
       }
       while(r<n){
       sum+=nums[r];
       while(sum>goal){
        sum-=nums[l];
        l++;
       }
       maxi+=(r-l+1);
       r++;
       }
       return maxi;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return ans(nums, goal) - ans(nums, goal - 1);
    }
};