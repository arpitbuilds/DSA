class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        int i=0;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[l],nums[i]);
                i++;
                l++;
            }
            else if(nums[i]==2){
                swap(nums[r],nums[i]);
                r--;
            }
            else{
                i++;
            }
        }
    }
};