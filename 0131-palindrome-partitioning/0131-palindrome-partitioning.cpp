class Solution {
public:
    bool check(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void fun(int ind,string s,vector<string>&path, vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            if(check(s,ind,i)==true){
                path.push_back(s.substr(ind,i-ind+1));
                fun(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        fun(0,s,path,ans);
        return ans;
    }
    
};