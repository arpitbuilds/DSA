class Solution {
public:
    int search(vector<int>& arr, int target) {
    int l=0;
    int n=arr.size();
    int h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1;
    }
};