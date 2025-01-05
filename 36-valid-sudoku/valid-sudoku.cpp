class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board)
    {
        char ch = board[row][col];
        board[row][col]='.';
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
            if(board[row][i]==ch) return false;
        }
        int r = row/3;
        int c =col/3;
        for(int i = 0 ;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[r*3+i][c*3+j]==ch) return false;
            }
        }
        board[row][col]=c;
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(isValid(i,j,board)==false)return false;
                }
            }
        }
        return true;
        
    }
};