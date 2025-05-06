class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=1;
        int n=arr.size();
        int ans=0;
        while(i<n){
            int lower=0;
            int upper=0;
            while(i<n && arr[i-1]==arr[i]){
                i++;
            } 
            while(i<n && arr[i-1]<arr[i]){
                upper++;
                i++;
            }
            while(i<n && arr[i]<arr[i-1]){
                lower++;
                i++;
            }
            if(lower && upper){
                ans=max(ans,lower+upper+1);
            }
        }
        return ans;
    }
};