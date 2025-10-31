class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board) {
        Arrays.fill(row, '.');
}
        Helper(0,n,board,ans);
         return ans;
    }
    public void Helper(int row,int n, char[][] board, List<List<String>> ans)
    {
        if(row==n)
        {
            List<String> temp = new ArrayList<>();
            for(int i = 0;i <n;i++)
            {
                StringBuilder sb = new StringBuilder("");
                for(int j=0;j<n;j++)
                {
                    sb.append(board[i][j]);
                }
                temp.add(sb.toString());
            }
            ans.add(temp);
            return;
        }
        for( int i = 0;i<n;i++)
        {
            if(isValid(board,row,i)==true)
            {
                board[row][i] ='Q';
                Helper(row+1,n,board,ans);
                board[row][i]='.';
            }
        }
    }
    public boolean isValid(char[][] board,int row, int col)
    {
        for(int i=0;i<board.length;i++)
        {
            if(board[i][col]=='Q') return false;
        }
        int tempr=row;
        int tempc = col;
        while(tempr>-1 && tempc>-1)
        {
            if(board[tempr][tempc]=='Q') return false;
            tempr-= 1;
            tempc-= 1;
        }
        tempr =row;
        tempc = col;
        while(tempr>-1 && tempc<board.length)
        {
            if(board[tempr][tempc]=='Q') return false;
            tempr-= 1;
            tempc+= 1;
        }
        return true;
    }
}