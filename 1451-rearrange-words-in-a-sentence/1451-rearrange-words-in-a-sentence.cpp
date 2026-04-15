class Solution {
public:
    string arrangeWords(string text) {
        text[0]=tolower(text[0]);
        map<int,vector<string>>mpp;
        stringstream ss(text);
        string x;
        while(ss>>x){
            mpp[x.size()].push_back(x);
        }
        string ans;
        for(auto it : mpp){
            for(auto x : it.second){
                ans+=x+" ";
            }
        }
        ans.pop_back();
        ans[0]=(ans[0]+'A'-'a');
        return ans;
    }
};