class Solution {
public:
    void solve(int ind,string s,vector<string>&v,string digi,unordered_map<char,string>&mpp){
        if(ind==digi.size()){
            v.push_back(s);
            return;
        }
        char x=digi[ind];
        string k=mpp[x];
        int n=k.size();
        for(int i=0;i<n;i++){
            s.push_back(k[i]);
            solve(ind+1,s,v,digi,mpp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        string s="";
        unordered_map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        solve(0,s,v,digits,mpp);
        return v;
    }
};