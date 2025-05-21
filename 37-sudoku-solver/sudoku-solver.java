class Solution {
    public void solveSudoku(char[][] board){
        solve(board);
    }
    public boolean solve(char[][] board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                {
                    for(char ch = '1'; ch<='9';ch++){
                        if(isPossible(board,i,j,ch)==true)
                        {
                            board[i][j]=ch;
                            if(solve(board)==true) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;// if no substitution works
                }
            }
        }
        return true;
    }
    boolean isPossible(char[][] board, int r, int c, char ch)
    {
        for(int i=0;i<9;i++){
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
        }
        int newR = r/3;
        int newC = c/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[newR*3+i][newC*3+j]==ch) return false;
            }
        }
        return true;
    }
}