class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
     int n=intervals.size();
     int i=0;
     int j=1;
     int cnt=0;
     while(j<n){
        vector<int>ci=intervals[i];
        vector<int>ni=intervals[j];
        int cs=ci[0];
        int ce=ci[1];
        int ns=ni[0];
        int ne=ni[1];
        if(ce<=ns){
            i=j;
            j++;
        }
        else if(ce<=ne){
            cnt++;
            j++;
        }
        else if(ce>ne){
            i=j;
            j++;
            cnt++;
        }
     }    
     return cnt;
    }
};