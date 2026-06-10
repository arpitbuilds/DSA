class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);
        for(auto it : bookings){
            int s=it[0];
            int e=it[1];
            int seats=it[2];
            diff[s-1]+=seats;
            diff[e]-=seats;
        }
        vector<int>ans(n);
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
          ans[i]=ans[i-1]+diff[i];
        }
        return ans;
    }
};