class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l=0;
        int r=0;
        int m=nums1.size();
        int n=nums2.size();
        while(l<m && r<n){
            if(nums1[l]!=nums2[r] && nums1[l]<nums2[r]){
              l++;
            }
            else if(nums1[l]!=nums2[r] && nums1[l]>nums2[r]){
                r++;
            }
            else{
                return nums1[l];
            }
        }
        return -1;
    }
};