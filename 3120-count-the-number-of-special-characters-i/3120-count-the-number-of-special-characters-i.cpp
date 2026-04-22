class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st;
        set<char>used;
        int cnt=0;
        for(auto it : word){
            st.insert(it);
        }
        for(int i=0;i<word.size();i++){
            if(st.count(tolower(word[i])) && st.count(toupper(word[i])) && !used.count(tolower(word[i]))){
                cnt++;
                used.insert(tolower(word[i]));
            }
        }
        return cnt;
    
    }
};