class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>stk;
         string ans;
        for(auto c : num){
            while(k>0 && !stk.empty() && stk.back()>c){
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
            while(k--){
                stk.pop_back();
            }
           
            for(auto c : stk){
                if(ans.empty() && c=='0'){
                    continue;
                }
                ans.push_back(c);
            }
        
        return ans.empty()?"0":ans;
    }
};