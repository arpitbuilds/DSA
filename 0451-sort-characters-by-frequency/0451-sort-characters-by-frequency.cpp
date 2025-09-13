#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char,int> &a, pair<char,int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;

        vector<pair<char,int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), compare);

        string result;
        for(auto &p : vec) {
            result.append(p.second, p.first);
        }

        return result;
    }
};
