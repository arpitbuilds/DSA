class Solution {
public:
    void solve(int ind,string &s,vector<string> &ans,string &digits,unordered_map<char, string> &mpp){
        if(ind==digits.size()){
            ans.push_back(s);
            return ;
        }
        char ch=digits[ind];
        string x=mpp[ch];
        int n=x.size();
        for(int i=0;i<n;i++){
            s.push_back(x[i]);
            solve(ind+1,s,ans,digits,mpp);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string s = "";
        if(digits.size()==0){
            return {};
        }
        vector<string> ans;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        solve(0,s,ans,digits,mpp);
        return ans;
    }
};