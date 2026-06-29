class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>>pq;
        for(auto it : points){
            int x=it[0];
            int y=it[1];
            int dis=x*x+y*y;
            pq.push({dis,x,y});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return result;
    }
};