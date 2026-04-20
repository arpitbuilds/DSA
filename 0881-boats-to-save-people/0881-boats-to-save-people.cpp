class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n=p.size();
        int l=0;
        int r=n-1;
        int cnt=0;
        sort(p.begin(),p.end());
        while(l<=r){
            if(p[l]+p[r]<=limit){
                l++;
            }
            r--;
            cnt++;
        }
        return cnt;
    }
};