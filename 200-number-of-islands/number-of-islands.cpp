class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    //do it using bfs or dfs just start with index if m[i][j]==1 
    //make all its surrounding index as 0 and start counting as given below
    // if dfs is used then stack space would be o(m*n) if bfs space would be o(m*n) for dfs
    int count = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]=='1'){
                count++;
                dfs(grid,i,j);
              }
        }
    }
       return count; 
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        vector<int> r = {-1,1,0,0};
        vector<int> c = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int row = i + r[k];
            int col = j + c[k];
            if(row>-1 && row<grid.size() && col>-1 && col<grid[0].size() && grid[row][col]=='1'){
             dfs(grid,row,col);
            }
        }
    }
};