class Solution {
public:
 void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(valid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
   
    bool valid(vector<vector<char>>& board,int r,int c,char x){
        for(int i=0;i<9;i++){
            if(board[r][i]==x){
                return false;
            }
            if(board[i][c]==x){
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==x){
                return false;
            }
        }
        return true;
    }
};