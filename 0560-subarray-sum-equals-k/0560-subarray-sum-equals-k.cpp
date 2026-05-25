class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int pf=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pf+=nums[i];
            int rem=pf-k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[pf]++;
        }
        return cnt;
    }
};