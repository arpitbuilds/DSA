class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;
        int n=nums.size();
        int j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==k){
                i++;
                j--;
                ans++;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};