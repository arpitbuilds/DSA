class Solution {
public:
    void merge(int l,int mid,int high, vector<int>&arr){
        vector<int>temp;
        int i=l;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]>=arr[j]){
                temp.push_back(arr[j]);
                j++;
            }
            else{
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k=l;k<=high;k++){
            arr[k]=temp[k-l];
        }
    }
    void ms(int l,int h,vector<int>&nums){
        if(l>=h){
            return;
        }
        int mid=l+(h-l)/2;
        ms(l,mid,nums);
        ms(mid+1,h,nums);
        merge(l,mid,h,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
     if (nums.empty()) return nums;
       int n=nums.size();
       ms(0,n-1,nums);
       return nums;
    }
};