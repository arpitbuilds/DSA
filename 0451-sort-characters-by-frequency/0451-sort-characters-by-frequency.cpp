class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        unordered_map<char,int>mpp;
        for(auto c : s){
            mpp[c]++;
        }
        for(auto it : mpp){
            pq.push({-it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int f=-pq.top().first;
            char c =pq.top().second;
            pq.pop();
            ans+=string(f,c);
        }
        return ans;
    }
};