class Solution {
public:
    string temp="";
    int getLucky(string s, int k) {
        for(auto c : s){
            int digi=c-'a'+1;
            temp+=to_string(digi);
        }
         while(k--){
            int sum=0;
            for(auto c : temp ){
                sum+=c-'0';
            }
            temp=to_string(sum);
         }
         return stoi(temp);
    }
};