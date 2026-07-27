class Solution {
public:
    int findMin(vector<int>&arr) {
       int n=arr.size();
       int mini=INT_MAX;
       int l=0;
       int r=n-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[l]<=arr[mid]){
            mini=min(mini,arr[l]);
            l=mid+1;
        }
        else{
            mini=min(mini,arr[mid]);
            r=mid-1;
        }
       }
       return mini;
    }
};