class Solution {
    private int[][] dir= {{0,1},{-1,0},{1,0},{0,-1}};

    public boolean exist(char[][] board, String word) {
        int index = 0;

        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                  if(Character.compare(board[i][j],word.charAt(index))==0){
                      if(existHelper(i,j,board,word,index)==true) return true;
                  }
            }
        }
        return false;
    }
    private boolean existHelper(int r,int c,char[][] board, String word,int in){
    if(in==word.length()){
        return true;
    }
    if(r>-1 && r<board.length && c>-1 && c<board[0].length) 
    {
        if(Character.compare(board[r][c],word.charAt(in))!=0) return false;
        
    }
    else return false;
    char temp = board[r][c];
    board[r][c]='#';
    for(int i=0;i<4;i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        if(existHelper(rr,cc,board,word,in+1)) return true;
    }
    board[r][c]=temp;

    return false;
}
}