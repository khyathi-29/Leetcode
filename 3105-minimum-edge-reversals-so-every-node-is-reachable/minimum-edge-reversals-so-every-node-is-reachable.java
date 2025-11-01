class Edge {
  final int to;
  final int w;
  Edge(int to, int w) { this.to = to; this.w = w; }
}
class Solution {
    public int[] minEdgeReversals(int n, int[][] edges) {
        int[] cost = new int[n];
        List<Edge>[] adj= new ArrayList[n];
        for(int i=0;i<n;i++) adj[i]= new ArrayList<>();
        for(int[] temp : edges)
        {
            int u = temp[0];
            int v = temp[1];
            adj[u].add(new Edge(v,0));
            adj[v].add(new Edge(u,1));
        }
        dfs(0,-1,adj,cost);
        dfs2(0,-1,adj,cost);
        return cost;
    }
    void dfs(int node,int parent, List<Edge>[] adj,int[] cost)
    {
        for(Edge i : adj[node])
        {
            int neighbour = i.to;
            int edgeCost = i.w;
           if(parent==neighbour) continue;
           cost[0]+=edgeCost;
           dfs(neighbour,node,adj,cost);

        }
    }
    void dfs2(int node,int parent, List<Edge>[] adj,int[] cost)
    {
        for(Edge i : adj[node])
        {
            int neighbour = i.to;
            int edgeCost = i.w;
           if(parent==neighbour) continue;
           cost[neighbour]= cost[node]+ (edgeCost==0?1:-1);
           dfs2(neighbour,node,adj,cost);
        }
    }
}


          
    
    
