class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        for(auto c : text){
            if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n'){
                mpp[c]++;
            }
        }
        int mini=INT_MAX;
        if(mpp.size()<5){
            return 0;
        }
        mpp['l']/=2;
        mpp['o']/=2;
        for(auto it : mpp){
            mini=min(mini,it.second);
        }
        return mini;
    }
};