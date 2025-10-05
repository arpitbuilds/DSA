class Solution {
public:
     bool can(int r , int c ,vector<string>&b,int n){
        int tr=r;
        int tc=c;
        while(r>=0 && c>=0){
            if(b[r--][c--]=='Q'){
                return false;
            }
        }
        r=tr;
        c=tc;
        while(c>=0){
            if(b[r][c--]=='Q'){
                return false;
            }
        }
        r=tr;
        c=tc;
        while(r<n && c>=0){
            if(b[r++][c--]=='Q'){
                return false;
            }
        }
        return true;
     }
     void solve(int c, vector<vector<string>>&res,vector<string>&b,int n ){
        if(c==n){
            res.push_back(b);
            return;
        }
        for(int r=0;r<n;r++){
            if(can(r,c,b,n)){
                b[r][c]='Q';
                solve(c+1,res,b,n);
                b[r][c]='.';
            }
        }

     }
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<string>b(n);
         string s(n,'.');
         for(int i=0;i<n;i++){
            b[i]=s;
         }
         solve(0,ans,b,n);
         return ans;
        
    }
};