class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        int n=start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<n && j<n){
            if(start[i]<end[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
