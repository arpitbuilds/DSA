class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int oc = 0;
        int zc = 0;
        int cnt=0;
        while (r < n) {
            if (s[r] == '0') {
                zc++;
            } else {
                oc++;
            }
            while (oc > k && zc > k) {
                if (s[l] == '0') {
                    zc--;
                } else {
                    oc--;
                }
                l++;
            }
            
                cnt+=r-l+1;
            
            r++;
        }
        return cnt;
    }
};