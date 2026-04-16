class Solution {
public:
    int countPairs(vector<int>& d) {
        int cnt=0;
        int mod=1e9+7;
        int ans=0;
        int maxi=*max_element(d.begin(),d.end());
        int maxii=2*maxi;
        unordered_map<int,int>mpp;
        for(auto x : d){
            for(int sum=1;sum<=maxii;sum<<=1){
                int target=sum-x;
                if(mpp.find(target)!=mpp.end()){
                    ans=(ans+mpp[target])%mod;
                }
            }
            mpp[x]++;
        }
        return ans%mod;
    }
};