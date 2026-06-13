class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inn) {
        vector<pair<int,int>>v;
        int cnt=0;
        for(auto it : inn){
            v.push_back({it[1],it[0]});
        }
        sort(v.begin(),v.end());
        int fe=v[0].first;
        for(int i=1;i<inn.size();i++){
            if(v[i].second<fe){
                cnt++;
            }
            else{
                fe=v[i].first;
            }
        }
        return cnt;
    }
};