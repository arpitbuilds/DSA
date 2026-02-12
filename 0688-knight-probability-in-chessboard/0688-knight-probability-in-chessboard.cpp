// class Solution {
// public:
//     double knightProbability(int n, int k, int row, int column) {
//         queue<pair<int,int>>q;
//         q.push({row,column});
//         int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
//         int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};
//         double total=pow(8.0,k);
//         while(k){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 int r=q.front().first;
//                 int c=q.front().second;
//                 q.pop();
//                 for(int i=0;i<8;i++){
//                     int nr=r+dr[i];
//                     int nc=c+dc[i];
//                     if(nr>=0 && nr<n && nc<n && nc>=0){
//                         q.push({nr,nc});
//                     }
//                 }
//             }
//             k--;
//         }
//         double valid=q.size();
//         return valid/total;
//     }
// };

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;

        vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        for (int move = 1; move <= k; move++) {
            vector<vector<double>> newDp(n, vector<double>(n, 0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    for (const auto& m : moves) {
                        int newR = r + m[0];
                        int newC = c + m[1];
                        if (isValid(newR, newC, n)) {
                            newDp[r][c] += dp[newR][newC] / 8.0;
                        }
                    }
                }
            }
            dp = newDp;
        }

        double probability = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                probability += dp[r][c];
            }
        }

        return probability;
    }

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
};