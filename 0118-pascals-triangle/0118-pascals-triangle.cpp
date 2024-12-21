class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int i=1 ; i<=numRows ; i++)
        {
            vector<int> b(i,1);
            {
                a[i-1]=b;
            }
        }
        for(int i=1;i<a.size();i++)
        {
            for(int j = 1 ; j<a[i].size()-1;j++)
            {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }

        return a;
    }
};