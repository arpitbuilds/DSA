class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            ans=ans+string(a,b);
        }
        return ans;
    }
};