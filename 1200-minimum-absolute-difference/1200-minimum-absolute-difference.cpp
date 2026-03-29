class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini=INT_MAX;
        vector<vector<int>>res;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
             int curd=arr[i]-arr[i-1];
             if(curd<mini){
                mini=curd;
                res.clear();
                res.push_back({arr[i-1],arr[i]});
             }
             else if(curd==mini){
                res.push_back({arr[i-1],arr[i]});
             }
        }   
        return res;
    }
};