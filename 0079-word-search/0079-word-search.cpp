class Solution {
public:
   bool dfs(vector<vector<char>>&b,string w,int i,int j, int ind,int m,int n){
    if(ind==w.size()){
        return true;
    }
    if(i<0 || i>=m ||  j>=n ||  j<0 || w[ind]!=b[i][j]){
        return false;
    }
    char temp=b[i][j];
    b[i][j]='$';
    bool op1=dfs(b,w,i-1,j,ind+1,m,n);
    bool op2=dfs(b,w,i,j+1,ind+1,m,n);
    bool op3=dfs(b,w,i+1,j,ind+1,m,n);
    bool op4=dfs(b,w,i,j-1,ind+1,m,n);
    b[i][j]=temp;
    return op1||op2||op3||op4;


   }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, m,  n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};