class Solution {
public:
    int appendCharacters(string s, string t) {
        int sn=s.size();
        int tn=t.size();
        int si=0;
        int ti=0;
        while(si<sn && ti<tn){
            if(s[si]==t[ti]){
                ti++;
            }
            si++;
        }
        return tn-ti;
    }
};