class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& giv) {
        vector<vector<int>> v;
          if(giv.size()<=1){
            return giv;
        }
        sort(giv.begin(), giv.end());
        v.push_back(giv[0]);
        for (int i = 1; i < giv.size(); i++) {
            if (v.back()[1] >= giv[i][0]) {
                v.back()[1] = max(v.back()[1], giv[i][1]);
            } else {
                v.push_back(giv[i]);
            }
        }
        return v;
    }
};