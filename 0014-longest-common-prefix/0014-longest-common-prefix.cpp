class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s=strs[0];
        string p=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=p[i]){
                break;
            }
            else{
                ans+=p[i];
            }
        }
        return ans;
    }
};