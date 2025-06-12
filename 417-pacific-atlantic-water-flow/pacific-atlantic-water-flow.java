class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int r = heights.length;
        int c = heights[0].length;
        int[][] visitedp = new int[r][c];
        int[][] visiteda = new int[r][c];
        List<List<Integer>> ans = new ArrayList<>();
        for(int i =0 ;i <heights.length;i++)
        {
            dfs(i,0,visitedp,heights);
            dfs(i,heights[0].length-1,visiteda,heights);
        }
        for(int i =0 ;i <heights[0].length;i++)
        {
            dfs(0,i,visitedp,heights);
            dfs(heights.length-1,i,visiteda,heights);
        }
        for(int i =0 ;i <heights.length;i++)
        {
            for(int j=0; j<heights[0].length;j++)
            {
                if(visitedp[i][j]==1 && visiteda[i][j]==1)
                {
                    List<Integer> t = new ArrayList<>();
                    t.add(i);
                    t.add(j);
                    ans.add(t);
                }
            }
        }
        return ans;

    }
    void dfs(int r, int c , int[][] visited,int[][] heights)
    {
          if(visited[r][c]==0)
          {
            visited[r][c]=1;
            int[] rr = {1,-1,0,0};
            int[] cc = {0,0,1,-1};
            for(int i =0;i<4;i++)
            {
                int nr = r+rr[i];
                int nc = c+cc[i];
                if(nr<heights.length && nr>-1 && nc<heights[0].length && nc>-1)
                {
                    if(heights[nr][nc]>=heights[r][c]){
                        dfs(nr,nc,visited,heights);
                    }
                }
            }
          }
    }
}