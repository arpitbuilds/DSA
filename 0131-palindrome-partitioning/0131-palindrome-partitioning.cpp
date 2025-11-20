class Solution {
public:
       bool check(int l,int r,string s){
        while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
        }
        return true;
    }
    void solve(int ind,vector<vector<string>>&ans,vector<string>&v,string s){
        if(ind==s.size()){
           ans.push_back(v);
           return;
        }
        for(int i=ind;i<s.size();i++){
            if(check(ind,i,s)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(i+1,ans,v,s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(0,ans,v,s);
        return ans;
    }
};