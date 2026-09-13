class Solution {
public:
    int solve(int x,vector<int>&w,int lim){
        int days=1;
        int load=0;
        for(auto it : w){
            if(load+it>x){
                days++;
                load=it;
            }
            else{
                load+=it;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>w, int days) {
        int sum=0;
        for(auto it :w){
            sum+=it;
        }
        int maxi=*max_element(w.begin(),w.end());
        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high){
            int i=low+(high-low)/2;
            if(solve(i,w,days)<=days){
                ans=i;
                high=i-1;
            }
            else{
                low=i+1;
            }
        }
        return ans;
    }
};