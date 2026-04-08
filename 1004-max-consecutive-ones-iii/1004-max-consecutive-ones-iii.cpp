class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int l=0;
        int r=0;
        int n=nums.size();
        int zero=0;
        while(r<n){
            if(nums[r]==0){
              zero++;
            }
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};