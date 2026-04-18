class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        for (char &it : p) {
            if (isalpha(it)) {
                it = tolower(it);
            } else {
                it = ' ';
            }
        }

        string ans;
        stringstream ss(p);
        string x;

        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> mpp;

        int maxi = 0;

        while (ss >> x) {
            if (ban.count(x)) {
                continue;
            }

            mpp[x]++;

            if (mpp[x] > maxi) {
                maxi = mpp[x];
                ans = x;
            }
        }

        return ans;
    }
};