class Solution {
public:
    int totalNQueens(int n) {
        string s(n,'.');
        int ans =0;
        vector<string> board(n,s);
        Helper(0,board,ans,n);
        return ans;
    }
    void Helper(int row , vector<string>& board, int& ans, int n){
        if(row==n) {
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(board,n,row,i)==true){
                board[row][i] ='Q';
                Helper(row+1,board,ans,n);
                board[row][i] ='.';
            }
        }

        return;
    }
    bool isValid(vector<string>& board,int n,int r,int c){
        int i = r;
        int j = c;
        while(i>-1 && j>-1){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i = r;
        j = c;
        while(i>-1 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        i = r;
        j = c;
        while(i>-1){
            if(board[i][c]=='Q') return false;
            i--;
        }
        while(j>-1){
            if(board[r][j]=='Q') return false;
            j--;
        }
        return true;
    }
};