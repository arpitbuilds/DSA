class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inn) {
        vector<vector<int>>ans;
        sort(inn.begin(),inn.end());
        for(auto it : inn){
            if(ans.empty() || ans.back()[1]<it[0]){
                ans.push_back(it);
            }
            else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }
        }
        return ans;
    }
};