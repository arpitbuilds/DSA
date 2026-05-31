class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int ind = 0;
        while (i < n) {
            char ch = chars[i];
            int cnt = 0;
            while (i < n && ch == chars[i]) {
                cnt++;
                i++;
            }
            chars[ind] = ch;
            ind++;
            if (cnt > 1) {
                string s = to_string(cnt);
                for (auto x : s) {
                    chars[ind++] = x;
                }
            }
        }
        return ind;
    }
};