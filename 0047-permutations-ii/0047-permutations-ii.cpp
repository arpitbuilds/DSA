class Solution {
public:
    void solve(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,vector<int>&freq){
        if(nums.size()==ds.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                if(i>0 && nums[i]==nums[i-1] && !freq[i-1]){
                    continue;
                }
                ds.push_back(nums[i]);
                freq[i]=1;
                solve(nums,ds,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int>freq(n,0);
        sort(nums.begin(),nums.end());
        solve(nums,ds,ans,freq);
        return ans;
    }
};