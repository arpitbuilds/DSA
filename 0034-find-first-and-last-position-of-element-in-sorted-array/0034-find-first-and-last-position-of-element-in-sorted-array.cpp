class Solution {
public:

        int lo(vector<int>&nums,int target){
        int ans=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }

    int fo(vector<int>&nums,int target){
        int ans=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int foo=fo(nums,target);
        int loo=lo(nums,target);
        res.push_back(foo);
        res.push_back(loo);
        return res;
    }
};