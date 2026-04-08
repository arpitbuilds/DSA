class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x=strs.size();
        sort(strs.begin(),strs.end());
        int n=strs[0].size();
        string ans="";
        string start=strs[0];
        string end=strs[x-1];
        for(int i=0;i<n;i++){
            if(start[i]==end[i]){
                ans+=start[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};