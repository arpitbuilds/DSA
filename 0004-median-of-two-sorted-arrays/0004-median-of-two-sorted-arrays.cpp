class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1=nums1.size();
    int s2=nums2.size();
    vector<int>final(s1+s2);
    int i=0;
    int j=0;
    int k=0;
    while(i<s1 && j<s2){
        if(nums1[i]<nums2[j]){
            final[k]=nums1[i];
            i++;
            k++;
        }
        else{
            final[k]=nums2[j];
            j++;
            k++;
        }
    } 
    while(i<s1){
        final[k]=nums1[i];
        i++;
        k++;
    }
    while(j<s2){
        final[k]=nums2[j];
        j++;
        k++;
    }
    if((s1+s2)%2==1){
        return final[(s1+s2)/2];
    }
    return (double)((final[(s1+s2)/2])+final[(s1+s2)/2-1])/2.0;
    }
};