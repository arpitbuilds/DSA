class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        int pf=0;
        unordered_map<int,int>mpp;
        int maxi=0;
        for(int i=0;i<n;i++){
            pf+=arr[i];
            if(pf==0){
                maxi=mai+1;
            }
            if(mpp.find(pf)!=mpp.end()){
              maxi = max(maxi, i-mpp[pf]);
            
            }
            else{
                mpp[pf]=i;
            }
        }
        return maxi;
    }
};