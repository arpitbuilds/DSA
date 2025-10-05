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
     void solve(int c, int &cnt,vector<string>&b,int n ){
        if(c==n){
           cnt++;
            return;
        }
        for(int r=0;r<n;r++){
            if(can(r,c,b,n)){
                b[r][c]='Q';
                solve(c+1,cnt,b,n);
                b[r][c]='.';
            }
        }

     }
    int totalNQueens(int n) {
        int cnt=0;
         vector<string>b(n);
         string s(n,'.');
         for(int i=0;i<n;i++){
            b[i]=s;
         }
         solve(0,cnt,b,n);
         return cnt;
        
    }
};