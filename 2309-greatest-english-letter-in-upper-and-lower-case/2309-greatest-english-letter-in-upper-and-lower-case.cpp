class Solution {
public:
    string greatestLetter(string s) {
        set<char>st;
        for(auto it : s){
            char upper=toupper(it);
            char lower=tolower(it);
            if(s.find(upper)!=string::npos && s.find(lower)!=string::npos){
                st.insert(upper);
            }
        }
        if(st.empty()){
            return "";
        }
        char ans=*st.rbegin();
        return string(1,ans);
    }
};