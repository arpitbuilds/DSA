class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums,vector<int>&freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i]=1;
                solve(ans,ds,nums,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        vector<int>freq(n,0);
        solve(ans,ds,nums,freq);
        return ans;
    }
};