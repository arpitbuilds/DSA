class Solution {
public:
    int solve(vector<int>&nums,int k){
        int i=0;
        int n=nums.size();
        map<int,int>mp;
        int r=0;
        int cnt=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>=k){
                cnt=cnt+(n-r);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            r++;
        }
        return cnt;
    }
    int countCompleteSubarrays(vector<int>& nums) {
    map<int,int>mpp;
    for(auto it:nums){
        mpp[it]++;
    }
    int k=mpp.size();
    return solve(nums,k)-solve(nums,k+1);
    }
};