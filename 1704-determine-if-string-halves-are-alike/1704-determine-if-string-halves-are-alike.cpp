class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt=0;
        int n=s.size();
        int midi=n/2;
        for(int i=0;i<midi;i++){
            if(vowels.count(s[i])){
                cnt++;
            }
            if(vowels.count(s[midi+i])){
                cnt--;
            }
        }
        return cnt==0;
    }
};