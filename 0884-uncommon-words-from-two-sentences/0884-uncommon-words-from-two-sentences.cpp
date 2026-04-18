class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       unordered_map<string,int>mpp1;
        unordered_map<string,int>mpp2;
        vector<string>ans;
       stringstream ss(s1);
       string x;
       while(ss>>x){
        mpp1[x]++;
       }
       stringstream ss2(s2);
       string y;
       while(ss2>>y){
        mpp2[y]++;
       }
       for(auto it : mpp1){
        if(it.second==1 && mpp2.count(it.first)==0){
            ans.push_back(it.first);
        }
       }
        for(auto it : mpp2){
        if(it.second==1 && mpp1.count(it.first)==0 ){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};