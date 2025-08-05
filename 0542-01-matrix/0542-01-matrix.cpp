class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    v[i][j]=1;;
                    q.push({{i,j},0});

                }
            }
        }
          int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dis[r][c]=d;
            for(int i=0;i<4;i++){
                int nrow=r+delr[i];
                int ncol=c+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && v[nrow][ncol]==0 ){
                    v[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return dis;
    }
};