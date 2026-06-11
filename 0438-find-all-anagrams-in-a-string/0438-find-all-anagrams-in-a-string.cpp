class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto it : p){
            mpp2[it]++;
        }
        int m=s.size();
        int n=p.size();
        for(int i=0;i<n;i++){
            mpp1[s[i]]++;
        }
        vector<int>ans;
        if(mpp1==mpp2){
            ans.push_back(0);
        }
        for(int i=n;i<m;i++){
            mpp1[s[i]]++;
            mpp1[s[i-n]]--;
            if(mpp1[s[i-n]]==0){
                mpp1.erase(s[i-n]);
            }
            if(mpp1==mpp2){
                ans.push_back(i-n+1);
            }

        }
        return ans;
    }
};