class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mpp;
        int ans=INT_MAX;
        for(auto c : word){
            mpp[c]++;
        }
        for(auto it : mpp){
            int x=it.second;
            int del=0;
            for(auto itt : mpp){
                int y=itt.second;
                if(y<x){
                 del+=y;
                }
                else if(y>x+k){
                    del+=(y-(x+k));
                }
            }
            ans=min(ans,del);
        }
        return ans;
    }
};