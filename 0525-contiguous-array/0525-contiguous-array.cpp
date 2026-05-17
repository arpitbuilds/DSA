class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int pf=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pf+=-1;
            }
            else{
                pf+=1;
            }
            if(mpp.find(pf)!=mpp.end()){
                maxi=max(maxi,i-mpp[pf]);
            }
            else{
            mpp[pf]=i;
            }
        }
        return maxi;
    }
};