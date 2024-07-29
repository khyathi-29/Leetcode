class Solution {
public:
    void solve(int col,int n, vector<string>& temp, vector<vector<string>>& ans,vector<int>& left, vector<int>& upDiag, vector<int>& downDiag)
    {
        if(col==n)
        {
            ans.push_back(temp);
        }
        for(int row=0; row<n; row++)
        {
            if(temp[row][col]=='.' && left[row]==0 && upDiag[row+col]==0 && downDiag[n-1+col-row]==0 )
            {
                 temp[row][col]='Q';
                 left[row]=1;
                 upDiag[row+col]=1;
                 downDiag[n-1-row+col]=1;
                 solve(col+1,n,temp,ans,left,upDiag,downDiag);
                temp[row][col]='.';
                 left[row]=0;
                 upDiag[row+col]=0;
                 downDiag[n-1-row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>> ans;
        vector<int> left(n,0);
        vector<int> upDiag(2*n-1,0);
        vector<int> downDiag(2*n-1,0);
        vector<string> temp(n);
        string s(n,'.');
     
        for(int i=0;i<n;i++)
        {
            temp[i]=s;
        }
        
        solve(0,n,temp,ans,left,upDiag,downDiag);
       return ans; 
    }
};