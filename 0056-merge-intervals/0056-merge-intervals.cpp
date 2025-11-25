class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& given ) {
        sort(given.begin(),given.end());
        vector<vector<int>>v;
        v.push_back(given[0]);
        for(int i=1;i<given.size();i++){
            if(v.back()[1]>=given[i][0]){
                v.back()[1]=max(v.back()[1],given[i][1]);
            }
            else{
                v.push_back(given[i]);
            }
        }
        return v;
        
    }
};