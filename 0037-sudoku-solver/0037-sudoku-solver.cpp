class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
            
        }
    int startRow = 3 * (row / 3); 
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == c) return false;
        }
    }
        return true;
    }
    bool solvesudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                for(char c ='1'; c <= '9';c++)
                {
                   if(isValid(board,i,j,c)==true)
                   {
                       board[i][j]=c;
                       if(solvesudoku(board)) return true;
                       else board[i][j]='.';
                     
                   }
                }
                  return false;
                }
            }
        }
      return true;  
    }

    void solveSudoku(vector<vector<char>>& board) {
        solvesudoku(board);
    }
};