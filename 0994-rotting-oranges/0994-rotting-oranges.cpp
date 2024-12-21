class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_count=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                }
                else if(grid[i][j]==1) fresh_count++;
                else;
            }
        }
        int nexti[4] = {0,+1,0,-1};
        int nextj[4] ={+1,0,-1,0};
        int level = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            level = q.front().second;
            for(int i=0;i<4;i++)
            {
                int r = row + nexti[i];
                int c = col + nextj[i];
                if( r >-1 && r<grid.size() && c > -1 && c< grid[0].size())
                {
                    if(grid[r][c]==1)
                    {
                        q.push(make_pair(make_pair(r,c),level+1));
                        grid[r][c]=2;
                        fresh_count--;
                    }
                }
            }
            q.pop();
        }
        if(fresh_count==0) return level;
        else return -1;
    }
};