class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
       int ans=0;
        for(auto str : arr1){
           string val=to_string(str);
           string prefix="";
           for(auto ch : val){
            prefix+=ch;
            st.insert(prefix);
           }
        }
        for(auto str : arr2){
            string val=to_string(str);
            string check="";
            for(auto ch : val){
                check+=ch;
                if(st.count(check)){
                    ans=max(ans,(int)check.size());
                }
            }
        }
        return ans;
    }
};