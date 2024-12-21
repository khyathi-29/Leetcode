class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(col[i]==-1){
            col[i]=0;
            if(bfs(graph,col,i)==false) return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph,vector<int> &col, int node)
    {
       queue<int> q;
       q.push(node);
       while(!q.empty())
       {
        int temp = q.front();
        q.pop();
        for(int i: graph[temp])
        {
            if(col[i]==-1){
             col[i]=!col[temp];
             q.push(i);
            }
            if(col[i]==col[temp]) return false;
        }
       }
       return true;
    }
    bool dfs(vector<vector<int>>& graph,vector<int> &col, int node)
    {
        for(int i: graph[node])
        {
           if(col[i]==-1){
            col[i]=!col[node];
              if(dfs(graph,col,i)==false) return false;
            }
            if(col[i]==col[node]) return false;
        }
        return true;
    }
};