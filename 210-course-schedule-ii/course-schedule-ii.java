class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        List<Integer>[] adj = new ArrayList[n];
        Stack<Integer> s = new Stack<>();
        int[] visited = new int[n];
        int[] pathVisited = new int[n];
        for(int i=0;i<n;i++) adj[i]= new ArrayList<>();
        for(int[] temp : prerequisites)
        {
            adj[temp[1]].add(temp[0]);
        }
        for( int i =0 ;i<n;i++){
            if(visited[i]==0)
            {
                if(DFS(i,adj,s,visited,pathVisited)==false) return new int[0];
            }
        }
        int[] ans = new int[n];
        int j =0;
        while(!s.isEmpty()) ans[j++]= s.pop();
         return ans;
    }
    public boolean DFS(int node, List<Integer>[] adj, Stack<Integer> s, int[] visited,int[] pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        for(int i : adj[node]){
            if(visited[i]==0) {
                if(DFS(i,adj,s,visited,pathVisited)==false) return false;
            }
            else{
                if(visited[i]==pathVisited[i]) return false;
            }
        }
        pathVisited[node] =0;
        s.push(node);
        return true;
        }
}