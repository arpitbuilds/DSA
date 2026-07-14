class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        vector<pair<int,int>>v;
        for(auto it : in){
            v.push_back({it[1],it[0]});
        }
        sort(v.begin(),v.end());
        int fe=v[0].first;
        int cnt=0;
        for(int i=1;i<in.size();i++){
            if(fe>v[i].second){
                cnt++;
            }
            else{
                fe=v[i].first;
            }
        }
        return cnt;
    }
};