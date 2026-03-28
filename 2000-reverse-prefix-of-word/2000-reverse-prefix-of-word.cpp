class Solution {
public:
    string reversePrefix(string word, char ch) {
       if(word.find(ch)==string::npos){
        return word;
       }
       int ind=word.find(ch);
       int l=0;
       int r=ind;
       while(l<r){
        swap(word[l],word[r]);
        l++;
        r--;
       } 
       return word;
    }
};