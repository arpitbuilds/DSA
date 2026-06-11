class Solution {
public:
    bool solve(string word,string p){
        int m=word.size();
        int n=p.size();
        unordered_map<char,char>wp;
        unordered_map<char,char>pw;
        for(int i=0;i<n;i++){
            if(wp.count(word[i]) && wp[word[i]]!=p[i]){
                return false;
            }
              if(pw.count(p[i]) && pw[p[i]]!=word[i]){
                return false;
            }
            pw[p[i]]=word[i];
            wp[word[i]]=p[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto it : words){
            if(solve(it,pattern)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};