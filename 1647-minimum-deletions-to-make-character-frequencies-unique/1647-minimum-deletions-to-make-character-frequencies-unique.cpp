class Solution {
public:
    int minDeletions(string s) {
        int cnt=0;
        unordered_set<int>st;
        unordered_map<int,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        for(auto it : mpp ){
            int freq=it.second;
            while(freq>0 && st.find(freq)!=st.end()){
                freq--;
                cnt++;
            }
            st.insert(freq);
        }
        return cnt;
    }
};