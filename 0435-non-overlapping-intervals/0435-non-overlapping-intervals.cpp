class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        vector<pair<int,int>>v;
        int n=in.size();
        for(auto it : in){
            v.push_back({it[1],it[0]});
        }
        sort(v.begin(),v.end());
        int cnt=0;
        int fe=v[0].first;
        for(int i=1;i<n;i++){
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