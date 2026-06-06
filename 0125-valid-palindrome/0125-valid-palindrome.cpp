class Solution {
public:
    bool check(string s){
        string orig=s;
        reverse(s.begin(),s.end());
        return s==orig;
    }
    bool isPalindrome(string s) {
        string ans="";
        for(auto it : s){
            if(isalnum(it)){
                ans+=tolower(it);
            }
        }
        return check(ans);
    }
};