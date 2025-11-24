class unionFind{
    public:
    vector<int> p;
    vector<int> s;
    unionFind(int n){
        int i =0;
        while(i<n){
            s.push_back(1);
            p.push_back(i);
            i++;
        }
    }
    int parent(int i){
        if(p[i]!=i) return p[i]=parent(p[i]);
        return i;
    }
    void addEdge(int i, int j){
        int pi = parent(i);
        int pj = parent(j);
        if(pi!=pj){
            if(s[pi]>s[pj]){
                s[pi]+=s[pj];
                p[pj]=pi;
            }
            else{
                s[pj]+=s[pi];
                p[pi]=pj;
            }
        }
        return;
    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unionFind dfs(n*n);
        int col = n;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                      for(vector<int> d : dir){
                        int nr = d[0]+i;
                        int nc = d[1]+j;
                        if(nc>-1 && nr>-1 && nc<n && nr<n && grid[nr][nc]==1){
                            dfs.addEdge(i*n+j,nr*n+nc);
                        }
                      }
                }
            }
        }
        int ans = 0;
        int i=0;
        while(i<n*n){
            ans = max(ans,dfs.s[i]);
            i++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                      set<int> s;
                      for(vector<int> d : dir){
                        int nr = d[0]+i;
                        int nc = d[1]+j;
                        if(nc>-1 && nr>-1 && nc<n && nr<n && grid[nr][nc]==1){
                            s.insert(dfs.parent(nr*n + nc));
                        }
                      }
                      int total =0;
                      for(int i : s){
                          total+=dfs.s[i];
                      }
                     ans = max (ans, total+1);
                }
            }
        }

        return ans;
    }
};