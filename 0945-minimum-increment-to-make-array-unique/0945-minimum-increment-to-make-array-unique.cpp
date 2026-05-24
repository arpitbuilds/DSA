class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            if(arr[i-1]>=arr[i]){
                cnt+=arr[i-1]-arr[i]+1;
                arr[i]=arr[i-1]+1;
            }
        }
        return cnt;
    }
};