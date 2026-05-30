class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mpp;
        unordered_set<int>st;
        int cnt=0;
        for(auto c : s){
            mpp[c]++;
        }
        for(auto it : mpp){
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