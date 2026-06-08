class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int>pf,sf;
        vector<int>ans;
        for(auto x : nums){
            sf[x]++;
        }
        for(auto x : nums){
            pf[x]++;
            if(--sf[x]==0){
                sf.erase(x);
            }
            ans.push_back(pf.size()-sf.size());
        }
        return ans;
    }
};