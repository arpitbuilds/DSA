class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // int n=hours.size();
        // int cnt=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((hours[i]+hours[j])%24==0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        long long cnt=0;
        unordered_map<long long,long long>mpp;
        for(auto it : hours){
            int t=it%24;
            int y=(24-t)%24;
            cnt+=mpp[y];
            mpp[t]++;
        }
        return cnt;
    }
};