class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1){
                i++;
            }
            if(s!=nums[i]){
                ans.push_back(to_string(s)+"->"+to_string(nums[i]));
            }
            else{
                ans.push_back(to_string(s));
            }
        }
        return ans;
    }
};