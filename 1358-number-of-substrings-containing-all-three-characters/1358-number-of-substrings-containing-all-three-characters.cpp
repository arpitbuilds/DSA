class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int n = s.size();
        int r = 0;
        vector<int> v(256, 0);
        int cnt=0;
        while (r < n) {
            v[s[r] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                cnt += n - r;
                v[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};