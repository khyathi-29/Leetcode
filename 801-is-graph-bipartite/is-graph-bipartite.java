class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] visited = new int[n];//colored
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                if(Bfs(i,visited,graph)==false) return false;
            }
        }
        return true;
    }

    boolean Dfs(int node, int[] visited,int[][] graph)
    {
        for(int i : graph[node]){
            if(visited[i]==0){
                visited[i] = -visited[node];
                if(Dfs(i,visited,graph)==false) return false;        
            }
            else{
                if(visited[i]==visited[node]) return false;
            }
        }
        return true;

    }
    boolean Bfs(int node, int[] visited,int[][] graph)
    {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        while(!q.isEmpty()){
            int no = q.poll();
            for(int i: graph[no]){
                if(visited[i]==0){
                    visited[i]=-visited[no];
                    q.add(i);
                }
                else{
                    if(visited[i]==visited[no]) return false;
                }
            }
        }
        return true;
    }
};