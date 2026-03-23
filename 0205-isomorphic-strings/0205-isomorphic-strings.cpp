class Solution {
public:
    bool check(string s,string t){
       if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char>mpp;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i]){
                    return false;
                }
            }
            mpp[s[i]]=t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
     return check(s,t)&&check(t,s);
    }
};