class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        List<Integer>[] adj = new ArrayList[n];
        int[] indegree = new int[n];
        for(int i=0;i<n;i++) adj[i]= new ArrayList<>();
        for(int[] temp : prerequisites)
        {
            adj[temp[1]].add(temp[0]);
            indegree[temp[0]]++;
        }
        int count =0;
        Queue<Integer> q = new LinkedList<>();
         for(int i=0;i<n;i++) if(indegree[i]==0) q.add(i);

        while(!q.isEmpty())
        {
            int node = q.poll();
            System.out.println(node);
            count++;
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.add(i);
            }
        }

        return count==n;
    }
}