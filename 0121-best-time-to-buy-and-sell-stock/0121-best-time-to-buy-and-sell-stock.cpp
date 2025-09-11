class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int l=0;
        int r=1;
        int n=nums.size();
        int maxi=0;
        while(r<=n){
            if(nums[l]<nums[r]){
                maxi=max(maxi,nums[r]-nums[l]);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxi;
    }
};