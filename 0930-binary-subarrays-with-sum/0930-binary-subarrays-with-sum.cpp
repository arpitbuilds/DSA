class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size();
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-goal;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};