class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        for(auto it : mpp){
            pq.push({-it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int x=-pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans+=string(x,ch);

        }
        return ans;
    }
};