class Solution {
public:
    int numberOfSubstrings(string nums) {
      int n=nums.size();
      int l=0;
      int r=0;
      int cnt=0;
      unordered_map<char,int>mpp;
       while(r<n){
        mpp[nums[r]]++;
        while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
            cnt+=n-r;
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        r++;
       }
       return cnt;
    }
};