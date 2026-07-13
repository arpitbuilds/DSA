class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<char,int>mpp;
        while(r<n){
            if(mpp.find(nums[r])!=mpp.end()){
                while(mpp.find(nums[r])!=mpp.end()){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0){
                        mpp.erase(nums[l]);
                    }
                    l++;
                }
            }
            mpp[nums[r]]++;
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};