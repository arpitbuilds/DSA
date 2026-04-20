class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(auto it : time){
            int t=it%60;
            int y=(60-t)%60;
            ans+=mpp[y];
            mpp[t]++;
        }
        return ans;
    }
};