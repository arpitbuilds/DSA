class Solution {
public:
    bool dfs(int ind, int i, int j,vector<vector<char>>&b,string w,int m ,int n){
        if(ind==w.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || b[i][j]!=w[ind]){
            return false;
        }
        char temp=b[i][j];
        b[i][j]='$';
        bool op1=dfs(ind+1,i-1,j,b,w,m,n);
        bool op2=dfs(ind+1,i,j+1,b,w,m,n);
        bool op3=dfs(ind+1,i+1,j,b,w,m,n);
        bool op4=dfs(ind+1,i,j-1,b,w,m,n);
        b[i][j]=temp;
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(0,i, j, board, word, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};