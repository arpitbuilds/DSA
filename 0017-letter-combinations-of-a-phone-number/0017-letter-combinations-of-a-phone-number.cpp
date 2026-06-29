class Solution {
public:
    void solve(int ind,string s,vector<string>&v,string d,unordered_map<char,string>&mpp){
        if(ind==d.size()){
            v.push_back(s);
            return;
        }
        char x=d[ind];
        string word=mpp[x];
        for(int i=0;i<word.size();i++){
            s+=word[i];
            solve(ind+1,s,v,d,mpp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string>v;
        string s="";
        solve(0,s,v,digits,mpp);
        return v;
    }
};