class Solution {
public:
    string ans = "";
    string solve(int l, int r, string s) {
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string odd = solve(i, i, s);
            string even = solve(i, i + 1, s);
            if (odd.size() > ans.size()) {
                ans = odd;
            } 
             if(even.size()>ans.size()){
                ans = even;
            }
        }
        return ans;
    }
};