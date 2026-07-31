class Solution {
public:
    string mergeAlternately(string s, string t) {
        int m=s.size();
        int n=t.size();
        int i=0;
        int j=0;
        string ans="";
        while(i<m && j<n){
              if(i<m){
                ans+=s[i];
                i++;
              }
              if(j<n){
                ans+=t[j];
                j++;
              }
        }
        while(i<m){
            ans+=s[i];
            i++;
        }
        while(j<n){
            ans+=t[j];
            j++;
        }
        return ans;
    }
};