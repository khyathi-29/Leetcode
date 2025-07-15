class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int number=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                number++;
                DFS(i,visited,isConnected);
            }
        }
        return number;
        
    }
    void DFS(int node, vector<bool>& visited, vector<vector<int>>& isConnected)
    {
        visited[node]=true;
       for(int j=0;j<visited.size();j++)
       {
            if(node!=j && !visited[j] && isConnected[node][j]==1) DFS(j,visited,isConnected);
       }
       return;
    }
};