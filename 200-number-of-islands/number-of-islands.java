class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
    public void dfs(int r, int c, char[][] grid){
        grid[r][c]='0';
        int[] rr = {1,-1,0,0};
        int[] cc = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int R = rr[i]+r;
            int C = cc[i]+c;
            if(C>-1 && C< grid[r].length && R>-1 && R<grid.length){
                if(grid[R][C]=='1') dfs(R,C,grid);
            }
        }
    }
}