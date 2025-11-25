class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& given, vector<int>& newi) {
        int i=0;
        vector<vector<int>>ans;
        while(i<given.size()){
            if(given[i][1]<newi[0]){
                ans.push_back(given[i]);
                i++;
            }
            else if(given[i][0]>newi[1]){
                // given.insert(given.begin()+i,newi);
                // return given;
                break;
            }
            else{
                newi[0]=min(newi[0],given[i][0]);
                newi[1]=max(newi[1],given[i][1]);
                i++;
                // given.erase(given.begin()+i);

            }
        }
        ans.push_back(newi);
        while(i<given.size()){
            ans.push_back(given[i]);
            i++;
        }

        return ans;
    }
};