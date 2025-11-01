class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> cost(n,0);
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int> temp : edges)
        {
            int u = temp[0];
            int v = temp[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        dfs(0,-1,adj,cost);
        dfs2(0,-1,adj,cost);
        return cost;
    }
    void dfs(int node,int parent, vector<vector<pair<int,int>>>& adj, vector<int>& cost)
    {
        for(auto i : adj[node])
        {
            int neighbour = i.first;
            int edgeCost = i.second;
           if(parent==neighbour) continue;
           cost[0]+=edgeCost;
           dfs(neighbour,node,adj,cost);

        }
    }
    void dfs2(int node,int parent, vector<vector<pair<int,int>>>& adj, vector<int>& cost)
    {
        for(auto i : adj[node])
        {
            int neighbour = i.first;
            int edgeCost = i.second;
           if(parent==neighbour) continue;
           cost[neighbour]= cost[node]+ (edgeCost==0?1:-1);
           dfs2(neighbour,node,adj,cost);
        }
    }
};