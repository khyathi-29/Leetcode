class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] inDegree = new int[numCourses];
        List<Integer>[] graph = new ArrayList[numCourses];
        int[] ans = new int[numCourses];
        int count=0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
          graph[i] = new ArrayList<>();
         }
        for(int[] temp : prerequisites)
        {
            int prereq = temp[1];
            int course= temp[0];
            inDegree[course]++;
            graph[prereq].add(course);
        }
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int course = q.poll();
            ans[count++]=course;
            for(int j: graph[course]){
                    inDegree[j]--;
                    if(inDegree[j]==0){
                        q.add(j);
                    }
                }
        }
       if(numCourses==count){
        return ans;
       }
       else return new int[0];
        
    }
}