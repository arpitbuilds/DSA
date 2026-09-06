class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int pf=0;
        int cnt=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            pf+=nums[i];
            int rem=pf-goal;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[pf]++;
        }
        return cnt;
    }
};