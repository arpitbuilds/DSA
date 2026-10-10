class Solution {
    public void solve(int i,ArrayList<ArrayList<Integer>>adj,boolean[]vis){
        vis[i]=true;
        for(int it: adj.get(i)){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
    }
    public int findCircleNum(int[][] mat) {
        ArrayList<ArrayList<Integer>>v=new ArrayList<>();
        int n=mat.length;
        for(int i=0;i<n;i++){
            v.add(new ArrayList<>());
        }
        boolean[]vis=new boolean[n];
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && i!=j){
                    v.get(i).add(j);
                    v.get(j).add(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                solve(i,v,vis);
            }
        }
        return cnt;
    }
}