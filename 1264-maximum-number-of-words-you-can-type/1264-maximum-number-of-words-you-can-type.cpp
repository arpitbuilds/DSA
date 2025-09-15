class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (auto it : brokenLetters) {
            st.insert(it);
        }
        int cnt = 0;
        int i = 0;
        int n = text.size();
        bool valid = true;
        for (int i = 0; i <= n; i++) {
            if (i == text.size() || text[i] == ' ') {
                if (valid) {
                    cnt++;
                }
                valid = true;
            } else {
                if (st.find(text[i]) != st.end()) {
                    valid = false;
                }
            }
        }
        return cnt;
    }
};