class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1){
            return 0;
        }
        int l=0;
        int r=0;
        int ans=0;
        int pro=1;
        while(r<n){
         pro*=nums[r];
         while(pro>=k){
            pro/=nums[l];
            l++;
         }
         ans+=r-l+1;
         r++;
        }
        return ans;
    }
};