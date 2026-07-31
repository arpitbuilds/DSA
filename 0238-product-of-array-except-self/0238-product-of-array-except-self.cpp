class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
     int zero=0;
     int p=1;
     vector<int>ans(n,0);
     for(int i=0;i<n;i++){
        if(nums[i]==0){
            zero++;
        }
        else{
            p*=nums[i];
        }
     }
     if(zero>1){
        return ans;
     }
     else if(zero==1){
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans[i]=p;
            }
            else{
                ans[i]=0;
            }
        }
     }
     else{
        for(int i=0;i<n;i++){
            ans[i]=p/nums[i];
        }
     }
     return ans;
    }
};