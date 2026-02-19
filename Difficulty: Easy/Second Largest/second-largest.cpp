class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int lar=-1;
        int slar=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>lar){
                slar=lar;
                lar=arr[i];
            }
            else if(arr[i]<lar && arr[i]>slar){
                slar=arr[i];
            }
        }
        return slar;
    }
};