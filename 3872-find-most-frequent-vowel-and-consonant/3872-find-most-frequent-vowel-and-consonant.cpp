class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mpp;
        for(auto ch:s){
            mpp[ch]++;
        }
        int maxv=0;
        int maxc=0;
        for(auto[ch,cnt]:mpp){
               if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxv=max(maxv,cnt);
               }
               else{
                maxc=max(maxc,cnt);
               }
        }
        return maxv+maxc;
    }
};