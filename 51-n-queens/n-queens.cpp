class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n,0);
        vector<int> col(n,0);
        string s(n,'.');
        vector<string> board(n,s);
        vector<vector<string>> ans;
        solve(0,n,board,ans);
        return ans;
        
    }
    void solve(int i, int n, vector<string>& board,vector<vector<string>>& ans)
    {
        if(n==i) {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(check(i,j,board)==true){
                board[i][j]='Q';
                solve(i+1,n,board,ans);
                board[i][j]='.';
            }
        }
        return;
    }
    bool check(int i, int j, vector<string>& board)
    {
        //row and column check for a given queen
        for(int k = 0; k<board.size();k++)
        {
            if(board[k][j]=='Q' || board[i][k]=='Q') return false;
        }

        //since we are filling row after row it will be sufficient if we check upper rows diaganol values only;
        int r = i;
        int c = j;
        while(r>-1 && c>-1)
        {
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r = i;
        c = j;
        while(r>-1 && c<board.size())
        {
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
};