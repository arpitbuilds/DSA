class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==k){
                return mid;
            }
            // if(nums[l]==nums[mid] && nums[mid]==nums[h]){
            //     l++;
            //     h--;
            //     continue;
            // }
            if(nums[l]<=nums[mid]){
                if(nums[l]<=k && k<=nums[mid]){
                 h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<=k && k<=nums[h]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};