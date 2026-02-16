class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int maxi = 0;
        int mini = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                maxi += 1;
                mini += 1;
            } else if (s[i] == ')') {
                maxi -= 1;
                mini -= 1;
            } else {
                mini -= 1;
                maxi += 1;
            }
            if (maxi < 0) {
                return false;
            }
            if (mini < 0) {
                mini = 0;
            }
        }
        return mini == 0;
    }
};