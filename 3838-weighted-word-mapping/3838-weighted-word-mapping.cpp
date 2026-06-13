class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mpp;
        int cnt=25;
        for(char ch='a';ch<='z';ch++){
            mpp[cnt]=ch;
            cnt--;
        }
         string ans="";
        for(auto w : words){
             int sum=0;
             for(auto ch : w){
                sum+=weights[ch-'a'];
             }
             int k=sum%26;
             ans+=mpp[k];
        }
        return ans;
    }
};