class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int tem = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]=tem;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int tem = matrix[i][j];
                matrix[i][j]= matrix[i][n-1-j];
                matrix[i][n-1-j]=tem;
            }
        }

     return ;   
    }
};