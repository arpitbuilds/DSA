class Solution {
public:
    bool solve(int x,vector<int>&arr,int m,int k){
        int cnt=0;
        int tot=0;
        for(auto it : arr){
            if(it<=x){
                cnt++;
            }
            else{
             tot+=cnt/k;
             cnt=0;
            }
        }
        tot+=cnt/k;
        if(tot>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int minDays(vector<int>&arr, int m, int k) {
        if((long long)m*k>arr.size()){
            return -1;
        }
        int mini=*min_element(arr.begin(),arr.end());
        int maxi=*max_element(arr.begin(),arr.end());
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,arr,m,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};