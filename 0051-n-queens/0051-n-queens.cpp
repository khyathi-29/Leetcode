class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
    void solve(int row,vector<string>& board,vector<vector<string>>& ans, int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isValid(row,i,board)!=false)
            {
                board[row][i]='Q';
                solve(row+1,board,ans,n);
                board[row][i]='.';
            }
        }
    }
    bool isValid(int row, int col,vector<string>& board)
    {
        for(int i=0;i<board.size();i++)
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
        while(tempr>-1 && tempc<board.size())
        {
            if(board[tempr][tempc]=='Q') return false;
            tempr-= 1;
            tempc+= 1;
        }
        return true;
    }

};