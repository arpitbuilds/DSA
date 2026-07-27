class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>v;
        for(auto it : strs){
            string x=it;
            sort(x.begin(),x.end());
            mpp[x].push_back(it);
        }
        for(auto it : mpp){
            v.push_back(it.second);
        }
        return v;
    }
};