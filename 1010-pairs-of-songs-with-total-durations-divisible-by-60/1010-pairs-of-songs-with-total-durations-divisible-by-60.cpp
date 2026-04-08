class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mpp[60]={};
        int res=0;
        for(auto it : time){
            int t=it%60;
            int y=(60-t)%60;
            res+=mpp[y];
            mpp[t]++;
        }
        return res;
    }
};