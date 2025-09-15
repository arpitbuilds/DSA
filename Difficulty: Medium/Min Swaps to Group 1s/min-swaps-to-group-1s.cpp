class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int n=arr.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                k++;
            }
        }
        int mini=INT_MAX;
        int zc=0;
        for(int i=0;i<k;i++){
            if(arr[i]==0){
                zc++;
            }
        }
        if(k==0){
            return -1;
        }
        mini=min(mini,zc);
        int s=0;
        int e=k-1;
        while(e+1<n){
        
            if(arr[s]==0){
                zc--;
            }
            if(arr[e+1]==0){
                zc++;
            }
            s++;
            e++;
            mini=min(mini,zc);
           
            
        }
        return mini;
    }
};