class Disjoint{
    public: 
    vector<int> parent;
    vector<int> size;
    Disjoint(int n){
        parent = vector<int>(n);
        size = vector<int>(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int maxArea(){
        int ans =0;
        for(int i=0;i<size.size();i++) ans = max(ans,size[i]);
        return ans;
    }
    int Uparent(int node){
           if(node==parent[node]) return node;
           else {
                 parent[node]= Uparent(parent[node]);
           }
           return parent[node];
    }
    void addEdge(int n1,int n2){
        int p1 = Uparent(n1);
        int p2 = Uparent(n2);
        if(p1==p2) return;
        else{
            if(size[p1]>size[p2]){
                size[p1]+=size[p2];
                parent[p2]=p1;
            }
            else {
                size[p2]+=size[p1];
                parent[p1]=p2;
            }
        }
    }
    
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size()*grid.size();
        Disjoint graph = Disjoint(n);
        int ans =0;
        int col =grid[0].size() ,row = grid.size();
        vector<int> rr = {0,0,1,-1};
        vector<int> cc = {1,-1,0,0};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int newR = i + rr[k];
                        int newC = j+cc[k];
                        if( newR>-1 && newR<row && newC>-1 && newC<col && grid[newR][newC]==1){
                            graph.addEdge(i*row + j,newR*row+newC);
                        }
                    }
                }
            }
        }
        ans = graph.maxArea();
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    set<int> s;
                    if(grid[i][j]==0){
                        for(int k=0;k<4;k++){
                        int newR = i + rr[k];
                        int newC = j+cc[k];
                         if( newR>-1 && newR<row && newC>-1 && newC<col && grid[newR][newC]==1){
                            s.insert(graph.Uparent(newR*row+newC));
                         }
                        }
                        int area =0;
                        for(int a: s){
                            area+= graph.size[a];
                        }
                        ans = max(ans,area+1);
                    }
                }
            }
          return ans;
        }
};