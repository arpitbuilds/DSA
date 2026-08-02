class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum=0;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        int lsum=0;
        for(int i=0;i<n-1;i++){
            tsum-=nums[i];
            lsum+=nums[i];
            int diff=tsum-lsum;
            if(diff%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};