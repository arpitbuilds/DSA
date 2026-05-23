class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rights=0;
        int n=nums.size();
        for(auto it : nums){
            rights+=it;
        }
        int cnt=0;
        long long lefts=0;
        for(int i=0;i<n-1;i++){
           lefts+=nums[i];
           rights-=nums[i];
           if(lefts>=rights){
            cnt++;
           }
        }
        return cnt;
    }
};