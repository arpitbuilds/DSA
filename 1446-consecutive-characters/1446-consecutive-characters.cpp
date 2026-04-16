class Solution {
public:
    int maxPower(string s) {
        int maxi=0;;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char>st;
            for (int j = i; j < s.size(); j++) {
                st.insert(s[j]);
                if (st.size() == 1) {
                    maxi = max(j-i+1, maxi);
                } else {
                   
                    break;
                }
            }
        }
        return maxi;
    }
};