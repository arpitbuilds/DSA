class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(auto it : arr1){
            string val=to_string(it);
            string pf="";
            for(auto ch : val){
                pf+=ch;
                st.insert(pf);
            }
        }
        int maxi=0;
        for(auto it :arr2){
            string val=to_string(it);
            string pf="";
            for(auto ch : val){
             pf+=ch;
             if(st.count(pf)){
                maxi=max(maxi,(int)pf.size());
             }
            }
        }
        return maxi;
    }
};