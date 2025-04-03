class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      queue<vector<int>> q;
      vector<int> rr = {+1,-1,0,0,-1,-1,+1,+1};
      vector<int> cc = {0,0,+1,-1,-1,+1,-1,+1};
      int nn = grid.size();
      if(grid[0][0]==1) return -1;
      q.push({0,0});
      int count =0;
      while(!q.empty()){
        int n = q.size();
        count++;
        for(int i=0;i<n;i++){
        auto t = q.front();
        q.pop();
        int r = t[0];
        int c = t[1];
        cout<<count<<" "<<r<<" "<<c<<" "<<endl;
        if(r==nn-1 && c==nn-1) return count;
        for(int k=0;k<8;k++){
            int i = r+rr[k];
            int j = c+cc[k];
            if(i>=0 && i<nn && j>=0 && j<nn && grid[i][j]!=1){
                q.push({i,j});
                grid[i][j]=1;
            }
        }
        
        }
        
      }
       return -1;
    }
};