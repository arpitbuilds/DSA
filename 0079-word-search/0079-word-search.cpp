class Solution {
public:
    bool dfs(int i,int j,int ind,int m,int n,vector<vector<char>>&b,string word){
        int delr[]={0,-1,0,1};
        int delc[]={-1,0,1,0};
        if(ind==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || b[i][j]!=word[ind]){
            return false;

        }
        char temp=b[i][j];
        b[i][j]='$';
        for(int k=0;k<4;k++){
            int nrow=i+delr[k];
            int ncol=j+delc[k];
            if(dfs(nrow,ncol,ind+1,m,n,b,word)){
                return true;
            }
        }
        b[i][j]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,m,n,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};