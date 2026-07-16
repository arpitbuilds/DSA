class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pg(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pg[i]=__gcd(maxi,nums[i]);
        }
        long long sum=0;
        sort(pg.begin(),pg.end());
        int l=0;
        int r=n-1;
        while(l<r){
            int x=__gcd(pg[l],pg[r]);
            l++;
            r--;
            sum+=x;
        }
        return sum;
    }
};