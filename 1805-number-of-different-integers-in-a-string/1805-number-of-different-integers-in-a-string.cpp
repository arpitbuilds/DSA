class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string>st;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(isdigit(word[i])){
                string ans="";
                while(word[i]=='0'){
                    i++;
                }
                while(isdigit(word[i])){
                    ans+=word[i];
                    i++;
                }
                st.insert(ans);
            }
        }
        return st.size();
    }
};