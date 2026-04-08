class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         int cnt=0;
         if(k<0){
            return 0;
         }
         unordered_map<int,int>mpp;
         for(auto it : nums){
            mpp[it]++;
         }
         for(auto it : mpp){
            int x=it.first;
            if(k==0){
                if(it.second>1){
                    cnt++;
                }
            }
            else{
            if(mpp.find(x+k)!=mpp.end()){
                cnt++;
            }
            }
         }
         return cnt;
    }
};