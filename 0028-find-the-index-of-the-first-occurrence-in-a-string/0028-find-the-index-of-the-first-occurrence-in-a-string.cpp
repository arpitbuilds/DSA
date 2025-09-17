class Solution {
public:
    int strStr(string s1, string s2) {
        int ans=-1;
        if(s1.find(s2)!=string::npos){
         ans=s1.find(s2);
        }
        else{
            return -1;
        }
        return ans;
    }
};