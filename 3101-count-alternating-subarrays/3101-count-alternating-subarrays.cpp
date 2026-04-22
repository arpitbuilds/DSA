class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long cnt=1;
        long long res=1;
        for(int i=1;i<nums.size();i++){
          if(nums[i-1]!=nums[i]){
            cnt++;
          }
          else{
            cnt=1;
          }
            res+=cnt;
        }
        return res;
    }
};