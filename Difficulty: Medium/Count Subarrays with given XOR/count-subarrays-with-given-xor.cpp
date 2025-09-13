class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mpp;
        int px=0;
        int cnt=0;
        for(auto x:arr){
            px=px^x;
            if(px==k){
                cnt++;
            }
        
        int need=px^k;
        if(mpp.find(need)!=mpp.end()){
            cnt+=mpp[need];
        }
        mpp[px]++;
    }
    return cnt;
    }
};