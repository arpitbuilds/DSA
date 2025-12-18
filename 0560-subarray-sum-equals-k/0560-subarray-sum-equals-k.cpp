class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int pf=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            pf+=nums[i];
            int rem=pf-k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[pf]+=1;
        }
        return cnt;
    }
};