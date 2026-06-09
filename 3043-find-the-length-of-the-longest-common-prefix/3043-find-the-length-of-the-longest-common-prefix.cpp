class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        int maxi=0;
        for(auto it : arr1){
            string pf="";
            string s=to_string(it);
            for(auto x : s){
                pf+=x;
                st.insert(pf);
            }
        }
        for(auto it : arr2){
            string pf="";
            string s=to_string(it);
            for(auto x : s){
                pf+=x;
                if(st.find(pf)!=st.end()){
                    maxi=max(maxi,(int)pf.size());
                }
            }
        }
        return maxi;
    }
};