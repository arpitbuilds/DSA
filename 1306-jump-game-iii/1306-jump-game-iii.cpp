class Solution {
public:
    bool solve(vector<int>&arr,int i,vector<int>&v,int n){
        if(i<0 || i>=n){
            return false;
        }
        if(v[i]){
            return false;
        }
        if(arr[i]==0){
            return true;
        }
        v[i]=true;
        return solve(arr,i+arr[i],v,n)|| solve(arr,i-arr[i],v,n);
    }
    bool canReach(vector<int>& arr, int start) {
    int n=arr.size();
    vector<int>vis(n,false);
    return solve(arr,start,vis,n);
    }
};