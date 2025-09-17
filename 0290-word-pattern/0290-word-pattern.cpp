class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == ' ' || i == s.length()) {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }
        if (pattern.length() != words.size()) {
            return false;
        }
        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (c2w.count(c) && c2w[c] != w)
                return false;
            if (w2c.count(w) && w2c[w] != c)
                return false;

            c2w[c] = w;
            w2c[w] = c;
        }

        return true;
    }
};