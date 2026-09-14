class Solution {
public:
    bool solve(vector<int>&nums,int t,int i){
        int sum=0;
        for(auto it : nums){
            sum+=ceil((double)it/i);
        }
        if(sum<=t){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int maxi=*max_element(nums.begin(),nums.end());
        int l=1;
        int h=maxi;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(solve(nums,threshold,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};