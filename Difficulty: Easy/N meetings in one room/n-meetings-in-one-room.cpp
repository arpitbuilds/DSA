class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int fe=v[0].first;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(v[i].second>fe){
                cnt++;
                fe=v[i].first;
            }
        }
        return cnt;
    }
};