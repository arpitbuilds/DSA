class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>res(n,-1);
       for(int i=0;i<n;i++){
        for(int s=1;s<n;s++){
            int ind=(i+s)%n;
            if(nums[ind]>nums[i]){
                res[i]=nums[ind];
                break;
            }
        }
       } 
       return res;
    }
};