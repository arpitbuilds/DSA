class Solution {
public:
          bool isvowel(char ch){
            if(ch=='a' || ch=='e'  || ch=='i' || ch=='o' || ch=='u'){
                return true;
            }
            else{
                return false;
            }
        }
    int countVowelSubstrings(string word) {
        int cnt=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            for(int j=i;j<n;j++){
                if(isvowel(word[j])){
                    st.insert(word[j]);
                    if(st.size()==5){
                        cnt++;
                    }
                }
                else{
                    break;
                }
            }

        }
        return cnt;
    }
};