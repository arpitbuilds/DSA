class Solution {
public:
    bool solve(string w , string p){
        unordered_map<char,char>wp;
        unordered_map<char,char>pw;
        for(int i=0;i<p.size();i++){
            if(wp.count(w[i]) && wp[w[i]]!=p[i]){
                return false;
            }
             if(pw.count(p[i]) && pw[p[i]]!=w[i]){
                return false;
            }
            wp[w[i]]=p[i];
            pw[p[i]]=w[i];
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