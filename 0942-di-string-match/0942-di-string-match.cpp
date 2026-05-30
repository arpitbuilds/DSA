class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans;
        int n=s.size();
        int l=0;
        int h=n;
        for(auto c : s){
            if(c=='I'){
                ans.push_back(l++);
            }
            else{
                ans.push_back(h--);
            }
        }
        ans.push_back(l);
        return ans;
    }
};