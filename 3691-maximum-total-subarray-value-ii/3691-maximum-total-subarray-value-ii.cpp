class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
    int LOG = __lg(n) + 2;
    vector<vector<int>> mx(LOG,vector<int>(n)), mn(LOG,vector<int>(n));
    iota(mx[0].begin(),mx[0].end(),0);
    iota(mn[0].begin(),mn[0].end(),0);
    for(int j=1;j<LOG;j++)
        for(int i=0;i+(1<<j)<=n;i++){
            int a=mx[j-1][i],b=mx[j-1][i+(1<<(j-1))];
            mx[j][i]=nums[a]>=nums[b]?a:b;
            a=mn[j-1][i];b=mn[j-1][i+(1<<(j-1))];
            mn[j][i]=nums[a]<=nums[b]?a:b;
        }
    auto qmx=[&](int l,int r){int k=__lg(r-l+1);auto a=mx[k][l],b=mx[k][r-(1<<k)+1];return nums[a]>=nums[b]?a:b;};
    auto qmn=[&](int l,int r){int k=__lg(r-l+1);auto a=mn[k][l],b=mn[k][r-(1<<k)+1];return nums[a]<=nums[b]?a:b;};

    using T=tuple<long long,int,int>;
    priority_queue<T> pq;
    set<pair<int,int>> vis;
    auto push=[&](int l,int r){
        if(l<0||r>=n||r<l||!vis.insert({l,r}).second)return;
        pq.push({(long long)nums[qmx(l,r)]-nums[qmn(l,r)],l,r});
    };
    push(0,n-1);
    long long ans=0;
    while(k--){
        auto[v,l,r]=pq.top();pq.pop();
        ans+=v;
        push(l+1,r);
        push(l,r-1);
    }
    return ans;
    }
};