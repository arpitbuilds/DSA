class Solution {
public:
    bool check(int x){
        int sum=0;
        while(x!=0){
            int digi=x%10;
            sum+=digi;
            x=x/10;
        }
        if(sum%2==0){
            return true;
        }
        return false;
    }
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++){
            if(check(i)){
                cnt++;
            }
        }
        return cnt;
    }
};