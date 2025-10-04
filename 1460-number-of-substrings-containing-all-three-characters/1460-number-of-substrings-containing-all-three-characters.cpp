class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,0);
        int i=0;
        int j=0;
         int ans=0;
            int res=0;
        while(i<s.size()){
            v[s[i]-'a']+=1;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                res=res+(s.size()-i);
                v[s[j]-'a']--;
                j++;
            }
          i++;
        }
        return res;
    }
};