class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long lsum=0;
        long long tsum=0;
        int cnt=0;
        int n=nums.size();
        for(auto it : nums){
            tsum+=it;
        }
        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            tsum-=nums[i];
            if(lsum>=tsum){
                cnt++;
            }
        }
        return cnt;
    }
};