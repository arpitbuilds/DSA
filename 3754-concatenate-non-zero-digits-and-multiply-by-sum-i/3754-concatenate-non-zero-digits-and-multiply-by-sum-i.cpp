class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        string ans="";
        vector<long long>v;
        while(n){
            long long digi=n%10;
            if(digi!=0){
            sum+=digi;
            ans=ans+to_string(digi);
            }
            n=n/10;
        }
        if(ans.empty()){
            return 0;
        }
        reverse(ans.begin(),ans.end());
        long long num=stoll(ans);
        long long x=sum*num;
        return x;
    }
};