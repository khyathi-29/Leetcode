class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);//colored
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(Bfs(i,visited,graph)==false) return false;
            }
        }
        return true;
    }
    bool Dfs(int node, vector<int>& visited,vector<vector<int>>& graph)
    {
        for(int i : graph[node]){
            if(visited[i]==-1){
                visited[i] = !visited[node];
                if(Dfs(i,visited,graph)==false) return false;        
            }
            else{
                if(visited[i]==visited[node]) return false;
            }
        }
        return true;

    }
    bool Bfs(int node, vector<int>& visited,vector<vector<int>>& graph)
    {
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int no = q.front();
            q.pop();
            for(int i: graph[no]){
                if(visited[i]==-1){
                    visited[i]=!visited[no];
                    q.push(i);
                }
                else{
                    if(visited[i]==visited[no]) return false;
                }
            }
        }
        return true;
    }
};