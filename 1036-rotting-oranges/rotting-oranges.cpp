class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int m = grid.size();
        int nn = grid[0].size();
        vector<int> row = {-1,1,0,0};
        vector<int> col = {0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push(make_pair(i,j));
            }
        }
        if(fresh==0 && q.size()==0) return 0;
        int level=0;
        int size = q.size();
        while(!q.empty()){
            level++;
            int n = q.size();
            cout<<"level "<<level<<endl;
            for(int i=0;i<n;i++){
             int r = q.front().first;
             int c = q.front().second;
             int n =q.size();
             q.pop();

             for(int i =0;i<4;i++){
                int r1 = r+row[i];
                int c1 = c+col[i];
                cout<<i<<"i r"<<r1<<" "<<c1<<endl;
                if(r1>-1 && r1<m && c1>-1 && c1<nn)
                  {
                    if(grid[r1][c1]==1){
                     cout<<r1<<" "<<c1<<endl;
                     fresh-=1;
                     grid[r1][c1]=2;
                     q.push(make_pair(r1,c1));
                   }
                  }

               }
        
             }
        }
        cout<<fresh<<endl;
        if(fresh==0) return level-1;
        else return -1;
    }
};