

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int maxi=-1;
        int n=arr.size();
        vector<int>ans;
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