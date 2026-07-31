class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string x;
        vector<string>v;
        while(ss>>x){
            v.push_back(x);
        }
        reverse(v.begin(),v.end());
        int n=v.size();
        string ans="";
        for(int i=0;i<n;i++){
           ans+=v[i];
           if(i!=n-1){
            ans+=" ";
           }
        }
        return ans;
    }
};