// Can be done using Dfs as well
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int& area,int& maxArea){
        grid[i][j]=0;
        area +=1;
        maxArea = max(maxArea,area);
        vector<int> row = {1,-1,0,0};
        vector<int> col = {0,0,1,-1};
        for(int k=0;k<4;k++){
            int nextr = i+row[k];
            int nextc = j+col[k];
            if(nextr<grid.size() && nextr>=0 && nextc<grid[i].size() && nextc>=0){
                if(grid[nextr][nextc]==1){
                    dfs(grid,nextr,nextc,area,maxArea);
                }
            }
        }
        return;
     } 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int maxArea=0;
     for(int i = 0;i <grid.size(); i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==1){
                int area=0;
                dfs(grid,i,j,area,maxArea);
                cout<<area<<endl;
            }
        }
     }
     return maxArea;  
    }
};