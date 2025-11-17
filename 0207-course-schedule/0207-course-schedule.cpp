class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
       
        vector<vector<int>>v(n);
        vector<int>ind(n,0);
        for(auto it : pre ){
          v[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            for(auto it : v[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it : v[x]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==n;
    }
};