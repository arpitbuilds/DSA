class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>freq,ind;
        int deg=0;
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==1){
                ind[nums[i]]=i;
            }
            if(freq[nums[i]]==deg){
                mini=min(mini,i-ind[nums[i]]+1);
            }
            if(freq[nums[i]]>deg){
                deg=freq[nums[i]];
                mini=i-ind[nums[i]]+1;
            }
        }
        return mini;
    }
};