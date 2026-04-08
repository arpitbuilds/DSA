class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        int n=words.size();
        for(int i=n-1;i>=0;i--){
             ans+=words[i];
             if(i!=0){
                ans+=" ";
             }
        }
        return ans;
    }
};