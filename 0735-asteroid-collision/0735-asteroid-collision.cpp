class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (ast[i] > 0) {
                v.push_back(ast[i]);
            } else {
                while (!v.empty() && v.back()>0 &&  v.back() < abs(ast[i])) {
                    v.pop_back();
                }
                if (!v.empty() && v.back()>0 && v.back() == abs(ast[i])) {
                    v.pop_back();
                } 
                else if (v.empty() || v.back() < 0) {
                    v.push_back(ast[i]);
                }
            }
        }
        return v;
    }
};