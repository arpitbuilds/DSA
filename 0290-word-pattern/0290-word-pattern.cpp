class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        string x;
        vector<string> word;
        while (ss >> x) {
            word.push_back(x);
        }
        unordered_map<char, string> cs;
        unordered_map<string, char> sc;
        for (int i = 0; i < p.size(); i++) {
            char ch = p[i];
            string w = word[i];
            if (cs.count(ch) && cs[ch] != w) {
                return false;
            }
            if (sc.count(w) && sc[w] != ch) {
                return false;
            }
            cs[ch] = w;
            sc[w] = ch;
        }
        return true;
    }
};