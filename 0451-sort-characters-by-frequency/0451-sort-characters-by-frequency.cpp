class Solution {
public:
   static bool compare(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        vector<pair<char,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),compare);
        string res="";
        for(auto p : v){
            res.append(p.second,p.first);
        }
        return res;

    }
};