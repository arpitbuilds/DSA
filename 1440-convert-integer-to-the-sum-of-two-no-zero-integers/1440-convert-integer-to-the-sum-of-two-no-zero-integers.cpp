class Solution {
public:
    bool check(int x){
        while(x>0){
            if(x%10==0){
                return false;
            }
            x=x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int rem=n-i;
            if(i>0 && rem>0 && check(i) && check(n-i)){
                v.push_back(i);
                v.push_back(n-i);
                return v;

            }
        }
        return {-1,-1};
    }
};