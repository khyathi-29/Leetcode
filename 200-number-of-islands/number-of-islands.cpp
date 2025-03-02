class Solution {
public:
    //do it using bfs or dfs just start with index if m[i][j]==1 
    //make all its surrounding index as 0 and start counting as given below
    // if dfs is used then stack space would be o(m*n) if bfs space would be o(m*n) for dfs
    int numIslands(vector<vector<char>>& grid) {
        int count = 0 ;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    count++;
                    //dfs(i,j,row,col,grid);
                    bfs(i,j,row,col,grid);
                }
            }
        }
        return count;
    }
        void bfs ( int r,int c,int row,int col, vector<vector<char>>& grid){
            queue<pair<int,int>> q;
            grid[r][c]='0';
            q.push({r,c});
            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
               // if(grid[i][j]=='1') grid[i][j]='0';
                vector<int> rr = {0,0,+1,-1};
                vector<int> cc = {-1,+1,0,0};
                for(int k=0;k<4;k++){
                   int R = i + rr[k];
                   int C = j+ cc[k];
                    if( R<row && R> -1 && C< col && C >-1 && grid[R][C]=='1'){
                        q.push({R,C});
                        grid[R][C]='0';
                    }
                }
            }
        }
        void dfs ( int r,int c,int row,int col, vector<vector<char>>& grid){
            if(r>=row || c>=col || r < 0 || c < 0) return;
            else{
            vector<int> rr = {0,0,+1,-1};
            vector<int> cc = {-1,+1,0,0};
            if(grid[r][c] == '1'){
            grid[r][c]='0';
            for(int i=0;i<4;i++){
                dfs(r+rr[i],c+cc[i],row,col,grid);
            }
            }
            }
        }

        
};