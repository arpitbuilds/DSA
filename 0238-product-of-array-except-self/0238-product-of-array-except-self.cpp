class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int n=nums.size();
        int wp=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                 wp*=nums[i];
            }
        }
        vector<int>v(n,0);
        if(zero>1){
            return v;
        }
        else if(zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    v[i]=wp;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                v[i]=wp/nums[i];
            }
        }
        return v;
    }
};