class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        for(int i=1;i<grid.size();i++){
            grid[i][0]=grid[i-1][0]+grid[i][0];
        }
        for(int i=1;i<grid[0].size();i++){
            grid[0][i]=grid[0][i-1]+grid[0][i];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[i].size();j++){
                  grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        return grid[m][n];
        
    }
};