class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        for(char &it : p){
            if(isalpha(it)){
                it=tolower(it);
            }
            else{
                it=' ';
            }
        }
        unordered_set<string>st(banned.begin(),banned.end());
        string ans="";
        stringstream ss(p);
        string x;
        unordered_map<string,int>mpp;
        while(ss>>x){
           mpp[x]++;
        }
        int maxi=0;
        for(auto it : mpp){
            if(it.second>maxi && st.find(it.first)==st.end()){
                maxi=it.second;
                ans=it.first;
            }
        }
    return ans;
    }
};