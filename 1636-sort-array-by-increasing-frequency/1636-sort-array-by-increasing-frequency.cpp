class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {

        map<int,int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for (auto it : mpp) {

            // {frequency, -element}
            pq.push({it.second, -it.first});
        }

        vector<int> ans;

        while (!pq.empty()) {

            int freq = pq.top().first;
            int ele = -pq.top().second;

            pq.pop();

            while (freq--) {
                ans.push_back(ele);
            }
        }

        return ans;
    }
};