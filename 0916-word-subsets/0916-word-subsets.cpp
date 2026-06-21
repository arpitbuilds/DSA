class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int> req(26, 0);
        for (auto w : words2) {
            vector<int> freq(26, 0);
            for (auto c : w) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                req[i] = max(req[i], freq[i]);
            }
        }
        for(auto word: words1){
            vector<int>freq(26,0);
            for(auto x : word){
                freq[x-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq[i]<req[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};