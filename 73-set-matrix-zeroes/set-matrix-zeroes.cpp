class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row0 = -1;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i =0 ;i<r;i++)
        {
            for(int j =0; j<c;j++)
            {
                if(matrix[i][j]==0 && i==0)
                {
                    row0 = 0;
                    matrix[0][j]=0;
                }
                else if( matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;

                }
            }
        }
        for(int i = 1 ;i<c;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=1 ;j<r;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=1;i<r;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j =1;j<c;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=1; i<r;i++)
            {
                matrix[i][0]=0;
            }
        }
        if(row0==0){
            for(int j=0; j<c;j++)
            {
                matrix[0][j]=0;
            }
        }
        
        
    }
};