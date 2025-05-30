class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mpp;
     for(auto it:nums){
        mpp[it]++;
     }
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     for(auto it:mpp){
        pq.push({it.second,it.first});
     }
     while(pq.size()>k){
        pq.pop();
     }
     vector<int>res;
     while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();

     }
     return res;
    }
};

    //  unordered_map<int,int>mpp;
    //     int n=nums.size();
    //     vector<vector<int>>freq(n+1);
    //     for(auto ele:nums){
    //         mpp[ele]++;

    //     }
    //     for(auto it:mpp){
    //         freq[it.second].push_back(it.first);
    //     }
    //     vector<int>res;
    //     for(int i=freq.size()-1;i>=0;i--){
    //         for(auto n:freq[i]){
    //             res.push_back(n);
    //             if(res.size()==k){        //tc and sc o(n)
    //                 return res;
    //             }
    //         }
    //     }
    //     return res;


        // unordered_map<int,int>mpp;
        // int n=nums.size();
        // for(auto num:nums){     //tc O(n log k)//sc o(n)
        //     mpp[num]++;
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        // for(auto &entry:mpp){
        //    minheap.push({entry.second, entry.first});
        //    while(minheap.size()>k){
        //     minheap.pop();
        //    }

        // }
        // vector<int> result;
        // while (!minheap.empty()) {
        //     result.push_back(minheap.top().second);
        //     minheap.pop();
        // }
        // return result;
