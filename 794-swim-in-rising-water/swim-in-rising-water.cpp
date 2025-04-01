class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        vector<int> rr = {+1,-1,0,0};
        vector<int> cc = {0,0,+1,-1};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minHeap;
        minHeap.push({grid[0][0],0,0});
        while(!minHeap.empty()){
            vector<int> temp = minHeap.top();
            minHeap.pop();
            int r = temp[1];
            int c = temp[2];
            int t = temp[0];
            if(c==grid.size()-1 && r==grid.size()-1) return t;
            for(int i=0;i<4;i++){
                int row = r+rr[i];
                int col = c+cc[i];
                if(row<grid.size() && row >-1 && col<grid.size() && col>-1){
                    if(visited.find({row,col})==visited.end()){
                        int temp = max(t,grid[row][col]);
                        visited.insert({row,col});
                        minHeap.push({temp,row,col});
                    }
                }
            }
            
        }
        return 0;
        
    }
};