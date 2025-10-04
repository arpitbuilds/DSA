class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>pq;
        set<int>s;
        for(auto x :nums){
            s.insert(x);  
        }
        for(auto x : s){
            pq.push(x);
        }
        if(pq.size()<3){
            return pq.top();
        }
        pq.pop();
        pq.pop();
        return pq.top();
    }
};