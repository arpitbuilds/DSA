class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int m=s.size();
        int n=t.size();
        while(i<m && j<n){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        return t.size()-j;
    }
};