class Solution {
public:
    int finddays(vector<int>&arr,int capacity){
        int n=arr.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]+sum>capacity){
                cnt++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& arr, int days) {
       int n=arr.size();
       int l=0;
       int h=0;
       for(int i=0;i<n;i++){
        if(arr[i]>l){
            l=arr[i];
        }
        h+=arr[i];

       } 
       while(l<=h){
        int mid=l+(h-l)/2;
        if(finddays(arr,mid)>days){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
       }
       return l;
    }
};