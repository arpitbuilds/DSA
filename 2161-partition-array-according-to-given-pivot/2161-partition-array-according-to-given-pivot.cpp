class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>result(nums.size(),0);
        int n=nums.size();
        int i=0;
        int j=n-1;
        int l=0;
        int r=n-1;
        while(i<n){
            if(nums[i]<pivot){
                result[l]=nums[i];
                l++;
            }
             i++;
        }
        while(j>=0){
            if(nums[j]>pivot){
                result[r]=nums[j];
                r--;
            }
             j--;
        }
        while(l<=r){
            result[l]=pivot;
            l++;
        }
        return result;
    }
};