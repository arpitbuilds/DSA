class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s=strs[0];
        int n=s.size();
        int x=strs.size();
        string p=strs[x-1];
        int cnt=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==p[i]){
                ans.push_back(s[i]);
            }
            else{
                break;
            }
        }
        return ans;
    }
};