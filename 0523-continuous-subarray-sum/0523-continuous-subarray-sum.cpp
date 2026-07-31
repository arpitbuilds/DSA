class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       int sum=0;
       mpp[0]=-1;
       int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=nums[i];
        if(mpp.find(sum%k)!=mpp.end()){
            if((i-mpp[sum%k])>=2){
                return true;
            }
        }
        else{
            mpp[sum%k]=i;
        }
       }
       return false;
    }
};