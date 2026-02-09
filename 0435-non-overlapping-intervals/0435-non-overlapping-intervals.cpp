class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      vector<pair<int,int>>v;
      int n=intervals.size();
      for(auto it : intervals){
        v.push_back({it[1],it[0]});
      }  
      sort(v.begin(),v.end());
      int cnt=0;
      int preve=v[0].first;
      for(int i=1;i<n;i++){
        if(v[i].second<preve){
            cnt++;
        }
        else{
            preve=v[i].first;
        }
      }
      return cnt;
    }
};