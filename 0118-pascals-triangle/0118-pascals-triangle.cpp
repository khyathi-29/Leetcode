class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int i=0;i<numRows;i++)
        {
            a[i]=vector<int>(i+1);
            for(int j=0;j<i;j++)
            {
                a[i][j]=0;
            }
        }
        for(int i=0;i<numRows;i++)
        {
            a[i][0]=1;
            a[i][a[i].size()-1]=1;
        }
        for(int i=1;i<numRows;i++)
        {
            for(int j=1;j<i;j++)
            {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }

       return a; 
    }
};