class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
        
    }
    void dfs(vector<vector<char>>& grid, int i, int j )
    {
        grid[i][j]='0';
        int r[4] = {+1,-1,0,0};
        int c[4] = {0,0,+1,-1};
        for(int k =0;k<4;k++)
        {
            int r1 = i+r[k];
            int c1 = j+c[k];
            if(r1>-1 && r1<grid.size() && c1>-1 && c1<grid[0].size())
            {
                if(grid[r1][c1]=='1') dfs(grid,r1,c1);
            }
        }
        return;
    }
};