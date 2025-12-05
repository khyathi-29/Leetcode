class UnionFind{
    int[] p;
    int[] s;
    public UnionFind(int n){
        p = new int[n];
        s = new int[n];
        for(int i=0;i<n;i++){
            p[i]=i;
            s[i]=1;
        }}
        int uParent(int i){
            if(p[i]!=i) return p[i]=uParent(p[i]);
            else return i;
        }
        void addEdge(int i, int j){
            int pi = uParent(i);
            int pj = uParent(j);
            if(pi!=pj){
                if(s[pi]>s[pj]){
                    p[pj]=pi;
                    s[pi]+=s[pj];
                }
                else {
                    p[pi]=pj;
                    s[pj]+=s[pi];
                }
            }
        }
    }

class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        UnionFind g = new UnionFind(n*n);
        int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1) continue;
                for(int k=0;k<4;k++){
                    int nr = i+dir[k][0];
                    int nc = j+dir[k][1];
                    if(nr>-1 && nr<n && nc>-1 && nc<n && grid[nr][nc]==1)
                    g.addEdge(i*n+j,nr*n+nc);
                }
            }
        }
       int ans =1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1){
                    Set<Integer> s = new HashSet<>();
                    for(int k=0;k<4;k++){
                    int nr = i+dir[k][0];
                    int nc = j+dir[k][1];
                    if(nr>-1 && nr<n && nc>-1 && nc<n && grid[nr][nc]==1)
                    s.add(g.uParent(nr*n+nc));
                }
                int temp =0;
                for(int ii : s){
                      temp += g.s[ii];
                }
                ans = Math.max(ans,1+temp);
                }
                else{
                    ans = Math.max(ans,g.s[i]);
                }
                }}

                return ans;
    }
}