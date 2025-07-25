class Solution {
public:
// use in degree and out degree of graphs
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        if(trust.size()< n-1) return -1;
        for(int i=0;i<trust.size();i++)
        {
            a[trust[i][1]]++;
            b[trust[i][0]]++;

        }
    
        for(int i= 1; i<n+1;i++ )
        {
            if(a[i]==n-1 && b[i]==0) return i;
        }
        return -1;
    }
};