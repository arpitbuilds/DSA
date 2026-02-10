class Solution {
public:
    void solve(int ind, vector<string>& ans, string s, map<char, string> mpp,
               string d) {
        if (ind == d.size()) {
            ans.push_back(s);
            return;
        }
        char ch = d[ind];
        string x = mpp[ch];
        int n = x.size();
        for (int i = 0; i < n; i++) {
            s.push_back(x[i]);
            solve(ind + 1, ans, s, mpp, d);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> mpp;
        string s = "";
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        solve(0, ans, s, mpp, digits);
        return ans;
    }
};