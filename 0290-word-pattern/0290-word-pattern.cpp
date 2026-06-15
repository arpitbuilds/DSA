class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        string x;
        vector<string>v;
        while(ss>>x){
            v.push_back(x);
        }
        unordered_map<string,char>sp;
        unordered_map<char,string>ps;
        if(p.size()!=v.size()){
            return false;
        }
        for(int i=0;i<p.size();i++){
            if(sp.count(v[i]) && sp[v[i]]!=p[i]){
                return false;
            }
            if(ps.count(p[i]) && ps[p[i]]!=v[i]){
                return false;
            }
            sp[v[i]]=p[i];
            ps[p[i]]=v[i];
        }
        return true;
    }
};