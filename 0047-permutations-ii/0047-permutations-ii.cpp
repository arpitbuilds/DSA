class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&ds,vector<int>&freq,vector<int>&nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                freq[i]=1;
                ds.push_back(nums[i]);
                solve(ans,ds,freq,nums);
                freq[i]=0;
                ds.pop_back();
                while(i+1<nums.size()  && nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(n,0);
        solve(ans,ds,freq,nums);
        return ans;
    }
};