class Solution {
public:
    int help(vector<int>&nums,int k){
        int l=0;
        int r=0;
        int n=nums.size();
        int cnt=0;
        int ans=0;
        if(k<0){
            return 0;
        }
        while(r<n){
            cnt+=nums[r]%2;
            while(cnt>k){
                cnt-=nums[l]%2;
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};