#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
}

class Solution {
public:
    string frequencySort(string s) {
     unordered_map<char,int>freq;
     for(auto c:s){
       freq[c]++;
     }
     vector<pair<char,int>>v(freq.begin(),freq.end());
     sort(v.begin(),v.end(),compare);
     string res;
     for(auto p : v){
        res.append(p.second,p.first);
     }
     return res;
    }
};
