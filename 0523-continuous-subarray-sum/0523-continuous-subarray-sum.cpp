class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int pf=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pf+=nums[i];
            if(mpp.find(pf%k)!=mpp.end()){
                if((i-mpp[pf%k])>=2){
                    return true;
                }
            }
            else{
                mpp[pf%k]=i;
            }
        }
        return false;
    }
};