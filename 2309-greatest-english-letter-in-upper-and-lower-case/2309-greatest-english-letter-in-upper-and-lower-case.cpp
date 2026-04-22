class Solution {
public:
    string greatestLetter(string s) {
        set<char> st;

        for(char ch : s) {
            char lower = tolower(ch);
            char upper = toupper(ch);

            if(s.find(lower) != string::npos && s.find(upper) != string::npos) {
                st.insert(upper);
            }
        }

        if(st.empty()) return "";

        char ans = *st.rbegin();
        return string(1, ans);
    }
};