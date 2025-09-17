class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char,int>mpp;
        for(auto ch: b){
            mpp[ch]++;
        }
        for(auto x :a){
            if(mpp[x]>0){
                mpp[x]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};