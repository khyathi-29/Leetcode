class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') DFS(i,0,board);
            if(board[i][n-1]=='O')DFS(i,n-1,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')DFS(0,i,board);
            if(board[m-1][i]=='O')DFS(m-1,i,board);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='I') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        return;
    }
    public void DFS(int i , int j, char[][] board)
    {
        int m = board.length;
        int n = board[0].length;
        int[][] dirs ={{0,1},{1,0},{-1,0},{0,-1}};
        board[i][j] = 'I';
        for( int[] dir : dirs)
        {
            int r = dir[0]+i;
            int c = dir[1]+j;
            if( r>-1 && c>-1 && r<m && c<n && board[r][c]=='O') DFS(r,c,board);
        }

        return ;
    }


}