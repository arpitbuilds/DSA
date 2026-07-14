class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int l = 0;
        int r = 0;
        int n = b.size();
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 5) {
                five++;
            } else if (b[i] == 10) {
                if (five < 1) {
                    return false;
                } else {
                    five--;
                    ten++;
                }
            } else {
                if (five > 0 && ten > 0) {
                    five -= 1;
                    ten -= 1;
                } else if (five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }
        return true;
    }
};