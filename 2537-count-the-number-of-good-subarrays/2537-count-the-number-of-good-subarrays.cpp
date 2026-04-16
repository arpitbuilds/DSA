class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,long long>mpp;
        long long pairs=0;
        int n=nums.size();
        int l=0;
        for(int i=0;i<nums.size();i++){
            pairs+=mpp[nums[i]];
            mpp[nums[i]]++;
            while(pairs>=k){
                ans=ans+n-i;
                mpp[nums[l]]--;
                pairs=pairs-mpp[nums[l]];
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};