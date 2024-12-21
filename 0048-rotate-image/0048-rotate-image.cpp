class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<matrix.size();i++)
        {
            for(int j =0;j<i;j++)
            {
                int temp = matrix[i][j];
                 matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        int k = n/2;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j =0;j<k;j++)
            {
                int temp = matrix[i][j];
                 matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
        
    }
};