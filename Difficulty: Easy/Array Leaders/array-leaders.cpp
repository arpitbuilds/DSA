

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int maxi=-1;
        vector<int>ans;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
           if(arr[i]>=maxi){
               maxi=arr[i];
               ans.push_back(maxi);
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};