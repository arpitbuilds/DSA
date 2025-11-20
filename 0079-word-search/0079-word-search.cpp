class Solution {
public: 
    bool dfs(int i,int j,int ind,vector<vector<char>>& b,string word,int m,int n){
        if(ind==word.size()){
            return true;
        }
        if(i<0 || i>=m || j>=n || j<0 || word[ind]!=b[i][j]){
            return false;
        }
        char temp=b[i][j];
        b[i][j]='$';
        bool op1=dfs(i-1,j,ind+1,b,word,m,n);
        bool op2=dfs(i,j+1,ind+1,b,word,m,n);
        bool op3=dfs(i+1,j,ind+1,b,word,m,n);
        bool op4=dfs(i,j-1,ind+1,b,word,m,n);
        b[i][j]=temp;

        return op1||op2||op3||op4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                   if(dfs(i,j,0,board,word,m,n)){
                    return true;
                   }
                }
            }
        }
        return false;
    }
};