class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        vector<int>res;
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(auto it : p){
            mpp2[it]++;
        }
       
       for(int i=0;i<k;i++){
        mpp1[s[i]]++;
       }
       if(mpp1==mpp2){
          res.push_back(0);
       }
       for(int i=k;i<n;i++){
          mpp1[s[i]]++;
          mpp1[s[i-k]]--;
          if(mpp1[s[i-k]]==0){
            mpp1.erase(s[i-k]);
          }
          if(mpp1==mpp2){
            res.push_back(i-k+1);
          }
       }
       return res;
    }
};