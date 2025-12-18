class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
         vector<int>ans(n,0);
        int pro=1;
        int zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                pro=pro*nums[i];
            }
        }
        if(zero>1){
            return ans;
        }
        else if(zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=pro;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=pro/nums[i];
            }
        }
        return ans;
    }
};