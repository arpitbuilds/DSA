class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string cur = a;
        int cnt = 1;
        while (cur.size() < b.size()) {
            cur = cur + a;
            cnt++;
        }
        if (cur.find(b) != string::npos) {
            return cnt;
        }
        cur = cur + a;
        cnt++;
        if (cur.find(b) != string::npos) {
            return cnt;
        }
        return -1;
    }
};