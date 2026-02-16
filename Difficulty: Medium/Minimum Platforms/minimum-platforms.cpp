class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int l=0;
        int r=0;
        int cnt=0;
        int mini=0;
        while(l<arr.size() && r<dep.size()){
            if(arr[l]<=dep[r]){
                cnt++;
                l++;
            }
            else{
                cnt--;
                r++;
            }
            mini=max(mini,cnt);
        }
        return mini;
    }
};
