class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
     int n=arr.size();
     int q=n/4;    
     int cnt=1;
     int cur=arr[0];
     if(n==1){
        return arr[0];
     }
     for(int i=1;i<n;i++){
        if(arr[i]==cur){
            cnt++;
        }
        else{
            cur=arr[i];
            cnt=1;
        }
        if(cnt>q){
            return cur;
        }
        
     }
     return -1;
    }
};