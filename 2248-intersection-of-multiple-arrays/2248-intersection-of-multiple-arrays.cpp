class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
               mpp[nums[i][j]]++;
            }
        }
        for(auto it : mpp){
            if(it.second==n){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};