class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n){
            return false;
        }
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto it : s1){
            mpp1[it]++;
        }
        for(int i=0;i<m;i++){
            mpp2[s2[i]]++;
        }
        if(mpp1==mpp2){
            return true;
        }
        for(int i=m;i<n;i++){
            mpp2[s2[i]]++;
            mpp2[s2[i-m]]--;
            if(mpp2[s2[i-m]]==0){
                mpp2.erase(s2[i-m]);
            }
            if(mpp1==mpp2){
                return true;
            }
        }
        return false;
    }
};