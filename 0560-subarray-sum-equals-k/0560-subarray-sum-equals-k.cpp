class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int cnt=0;
        int sum=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};