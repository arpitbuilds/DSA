class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& given, vector<int>& newi) {
        int i=0;
        while(i<given.size()){
            if(given[i][1]<newi[0]){
                i++;
            }
            else if(given[i][0]>newi[1]){
                given.insert(given.begin()+i,newi);
                return given;
            }
            else{
                newi[0]=min(newi[0],given[i][0]);
                newi[1]=max(newi[1],given[i][1]);
                given.erase(given.begin()+i);

            }
        }
        given.push_back(newi);
        return given;
    }
};