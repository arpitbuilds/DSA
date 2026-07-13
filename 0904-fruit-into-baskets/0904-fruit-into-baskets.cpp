class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int k=2;
        int l=0;
        int r=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        int maxi=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                   mpp.erase(nums[l]);
                }
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};