class Solution {
public:
    int minimumDeletions(string word, int k) {

        int ans = INT_MAX;

        unordered_map<char,int> mpp;

        for(auto c : word){
            mpp[c]++;
        }

        for(auto it : mpp){

            int x = it.second;
            int del = 0;

            for(auto p : mpp){

                int freq = p.second;

                if(freq < x){
                    del += freq;
                }
                else if(freq > x + k){
                    del += (freq - (x + k));
                }
            }

            ans = min(ans, del);
        }

        return ans;
    }
};